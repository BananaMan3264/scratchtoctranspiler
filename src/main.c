#include <stdio.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>
#include "std_vector.h"
#include "types.h"
#include "parsejson.h"
#include "util.h"
#include "buildccode.h"

char* sprite_index;


int main(int argc, char**argv)
{
	sprite_index = "1";

	int spritecount = 3;

	//if (argc < 2) {
	//	printf("Error: no arguments supplied!\n");
	//	exit(-1);
	//}
	//
	//const char* filePath = argv[1];
	//FILE* json = fopen(filePath, "r");
	//if (json == NULL)
	//{
	//	printf("Error opening file - File could not be found!\n");
	//	exit(-1);
	//}

	FILE* json = fopen("../../../scratch/Project/project.json", "r");

	if (!json)
	{
		printf("Error opening file - file could not be opened!\n");
		exit(-1);
	}

	fseek(json, 0, SEEK_END);
	size_t bufferSize = ftell(json);
	fseek(json, 0, SEEK_SET);

	if (bufferSize < 0)
	{
		printf("Error opening file - file size could not be ascertained!\n");
		exit(-1);
	}
	if (bufferSize == 0)
	{
		printf("Error opening file - file was empty!");
		exit(-1);
	}

	char* text = malloc(bufferSize); if (!text) { printf("Malloc error!"); exit(-1); }

	if (text == NULL)
	{
		printf("Malloc Error.");
		exit(-1);
	}

	fread(text, 1, bufferSize, json);

	struct json_object* project = json_tokener_parse(text);
	
	spritecount = json_object_array_length(json_object_object_get(project, "targets"));

	FILE* mainh = fopen("../../../output/generated/output.h", "w");
	FILE* output = fopen("../../../output/generated/output.c", "w");
	FILE* scheduler = fopen("../../../output/generated/schedule.c", "w");

	int si = 0;
	sprite_index = malloc(20);

	fprintf(output, "#define YIELD TRUE_YIELD;\n#include \"../runtime/scratch.h\"\n#include \"../runtime/motion.h\"\n#include \"../runtime/looks.h\"\n#include \"../runtime/sound.h\"\n");
	fprintf(output, "#include \"../runtime/operators.h\"\n#include \"../runtime/control.h\"\n#include \"../runtime/sensing.h\"\n#include \"../runtime/data.h\"\n#include \"../runtime/pen.h\"\n");
	fprintf(output, "#include <libco.h>\n\nextern cothread_t scheduler;\nextern bool delete_thread; \n\n");

	fprintf(scheduler, "#include<SDL2/SDL.h>\n#include<libco.h>\n#include\"output.h\"\n#include\"../runtime/main.h\"\n#include\"../runtime/types.h\"\n#include\"../schedule_manager.h\"\n\n");
	fprintf(scheduler, "extern bool keysdown[];\nextern int keysdownheld[];\nThreadList threads;\ncothread_t scheduler;\ncothread_t draw_thread;\nbool delete_thread = false;\nextern int activeSprite;\n\n");
	fprintf(scheduler, "\nvoid RunScheduler()\n{\n\tInitialiseThreads();\n\n\tscheduler = co_active();\n\n");

	vecFunction* functions_arr = malloc(sizeof(vecFunction) * spritecount);

	for (int i = 0; i < spritecount; i++)
	{
		si = i;

		fprintf(scheduler, "\t_%i_Init();\n", i);

		snprintf(sprite_index, sizeof(sprite_index), "%i", si);

		struct json_object* blocks = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), si), "blocks");

		vecFunction functions = ParseText(blocks);

		for (int i = 0; i < functions.length; i++)
		{
			printf("Function: %s\n", functions.data[i].proccode.data);
			for (int j = 0; j < functions.data[i].blocks.length; j++)
			{
#define this functions.data[i].blocks.data[j]
				printf("\tBlock: %s\n\tArgs: %i\n", this.opcode.data, this.args);
#undef this
			}
			printf("\n");
		}

		struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), si), "variables");

		PrintData(json_object_object_get(project, "targets"));

		struct json_object* lists = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), si), "lists");

		GetFullProgram(mainh, output, scheduler, vars, lists, functions, blocks);
		functions_arr[i] = functions;
	}

	bool** FunctionsPresent = malloc(sizeof(bool*) * spritecount);

	for (int i = 0; i < spritecount; i++) 
	{
		FunctionsPresent[i] = malloc(FunctionEventsLength);
	}

	for (int j = 0; j < spritecount; j++)
	{
		for (int i = 0; i < FunctionEventsLength; i++)
		{
			FunctionsPresent[j][i] = false;
		}

		for (int i = 0; i < functions_arr[j].length; i++)
		{
			FunctionsPresent[j][functions_arr[j].data[i].opcode] = true;
		}

		if (FunctionsPresent[j][event_whenflagclicked])
		{
			for (int i = 0; i < functions_arr[j].length; i++)
			{
				if (functions_arr[j].data[i].opcode == event_whenflagclicked)
				{
					fprintf(scheduler, "\tAddThread(THREAD(co_create(64 * 1024, %s),%i));\n", functions_arr[j].data[i].proccode.data, j);
				}
			}
		}
	}
	fprintf(scheduler, "\n\twhile (1)\n\t{\n");
	fprintf(scheduler, "\t\tfor (int i = 0; i < threads.length; i++)\n\t\t{\n\t\t\tactiveSprite = threads.data[i].index;\n\t\t\tco_switch(threads.data[i].thread);\n\t\t\tif (delete_thread) { RemoveThread(i); i--;  delete_thread = false; }\n\t\t}\n");

	for (int j = 0; j < spritecount; j++)
	{
		for (int i = 0; i < FunctionEventsLength; i++)
		{
			FunctionsPresent[j][i] = false;
		}

		for (int i = 0; i < functions_arr[j].length; i++)
		{
			FunctionsPresent[j][functions_arr[j].data[i].opcode] = true;
		}

#define addkey(scancode, event) if (FunctionsPresent[j][event]){fprintf(scheduler, "\t\tif (keysdownheld[" #scancode "] == 1)\n\t\t{\n");for (int i = 0; i < functions_arr[j].length; i++){if (functions_arr[j].data[i].opcode == event){fprintf(scheduler, "\t\t\tAddThread(THREAD(co_create(64 * 1024, %s),%i));\n", functions_arr[j].data[i].proccode.data, j);}}fprintf(scheduler, "\t\t}\n");}

		addkey(SDL_SCANCODE_A, event_whenkeypressed_a)
		addkey(SDL_SCANCODE_B, event_whenkeypressed_b)
		addkey(SDL_SCANCODE_C, event_whenkeypressed_c)
		addkey(SDL_SCANCODE_D, event_whenkeypressed_d)
		addkey(SDL_SCANCODE_E, event_whenkeypressed_e)
		addkey(SDL_SCANCODE_F, event_whenkeypressed_f)
		addkey(SDL_SCANCODE_G, event_whenkeypressed_g)
		addkey(SDL_SCANCODE_H, event_whenkeypressed_h)
		addkey(SDL_SCANCODE_I, event_whenkeypressed_i)
		addkey(SDL_SCANCODE_J, event_whenkeypressed_j)
		addkey(SDL_SCANCODE_K, event_whenkeypressed_k)
		addkey(SDL_SCANCODE_L, event_whenkeypressed_l)
		addkey(SDL_SCANCODE_M, event_whenkeypressed_m)
		addkey(SDL_SCANCODE_N, event_whenkeypressed_n)
		addkey(SDL_SCANCODE_O, event_whenkeypressed_o)
		addkey(SDL_SCANCODE_P, event_whenkeypressed_p)
		addkey(SDL_SCANCODE_Q, event_whenkeypressed_q)
		addkey(SDL_SCANCODE_R, event_whenkeypressed_r)
		addkey(SDL_SCANCODE_S, event_whenkeypressed_s)
		addkey(SDL_SCANCODE_T, event_whenkeypressed_t)
		addkey(SDL_SCANCODE_U, event_whenkeypressed_u)
		addkey(SDL_SCANCODE_V, event_whenkeypressed_v)
		addkey(SDL_SCANCODE_W, event_whenkeypressed_w)
		addkey(SDL_SCANCODE_X, event_whenkeypressed_x)
		addkey(SDL_SCANCODE_Y, event_whenkeypressed_y)
		addkey(SDL_SCANCODE_Z, event_whenkeypressed_z)

		addkey(SDL_SCANCODE_0, event_whenkeypressed_0)
		addkey(SDL_SCANCODE_1, event_whenkeypressed_1)
		addkey(SDL_SCANCODE_2, event_whenkeypressed_2)
		addkey(SDL_SCANCODE_3, event_whenkeypressed_3)
		addkey(SDL_SCANCODE_4, event_whenkeypressed_4)
		addkey(SDL_SCANCODE_5, event_whenkeypressed_5)
		addkey(SDL_SCANCODE_6, event_whenkeypressed_6)
		addkey(SDL_SCANCODE_7, event_whenkeypressed_7)
		addkey(SDL_SCANCODE_8, event_whenkeypressed_8)
		addkey(SDL_SCANCODE_9, event_whenkeypressed_9)

#undef addkey()
	}
	fprintf(scheduler, "\t\tRender();\n\t}\n}\n");

	fclose(mainh);
	fclose(output);
	fclose(scheduler);

	return 0;
}