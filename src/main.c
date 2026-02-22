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

bool* doublevar;

typedef struct StringList
{
	void** data;
	size_t allocated_size;
	size_t length;
} StringList;

StringList broadcasts;

void initialiseBroadcasts()
{
	broadcasts.data = malloc(sizeof(void*) * 8); if (!broadcasts.data) { printf("Malloc error!"); exit(-1); }
	broadcasts.allocated_size = 8;
	broadcasts.length = 0;
}

void resizeBroadcasts(int length)
{
	broadcasts.allocated_size = length;
	void** temp = realloc(broadcasts.data, broadcasts.allocated_size * sizeof(void*));
	if (!temp) { exit(-1); }
	broadcasts.data = temp;
}

void addToBroadcasts(void* data)
{
	if (broadcasts.length + 1 > broadcasts.allocated_size)
	{
		resizeBroadcasts(broadcasts.allocated_size * 2);
	}
	broadcasts.data[broadcasts.length] = data;
	broadcasts.length++;
}

bool broadcastsContains(void* item)
{
	for (int i = 0; i < broadcasts.length; i++)
	{
		if (strcmp(item, broadcasts.data[i]) == 0)
		{
			return true;
		}
	}
	return false;
}

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
	FILE* schedulerh = fopen("../../../output/generated/schedule.h", "w");

	initVarIdeas();

	int si = 0;
	sprite_index = malloc(20);

	fprintf(output, "#define YIELD TRUE_YIELD;\n#include \"../runtime/scratch.h\"\n#include \"../runtime/motion.h\"\n#include \"../runtime/looks.h\"\n#include \"../runtime/sound.h\"\n");
	fprintf(output, "#include \"../runtime/operators.h\"\n#include \"../runtime/control.h\"\n#include \"../runtime/sensing.h\"\n#include \"../runtime/data.h\"\n#include \"../runtime/pen.h\"\n");
	fprintf(output, "#include \"../runtime/turbowarp.h\"\n#include \"../runtime/event.h\"\n#include \"schedule.h\"\n");
	fprintf(output, "#include <libco.h>\n\nextern cothread_t scheduler;\nextern bool delete_thread;\nextern bool stop_all;\nextern bool stop_other;\nextern bool gc_enabled;\nextern int activeSprite;\n\n");

	fprintf(scheduler, "#include<SDL2/SDL.h>\n#include<libco.h>\n#include\"output.h\"\n#include\"../runtime/main.h\"\n#include\"../runtime/types.h\"\n#include\"../schedule_manager.h\"\n\n");
	fprintf(scheduler, "extern bool keysdown[];\nextern int keysdownheld[];\nThreadList threads;\ncothread_t scheduler;\ncothread_t draw_thread;\nbool delete_thread = false;\nbool stop_all = false;\nbool stop_other = false;\nextern int activeSprite;\n\n");
	fprintf(scheduler, "\nvoid RunScheduler()\n{\n\tInitialiseThreads();\n\n\tscheduler = co_active();\n\n");

	fprintf(schedulerh, "#include \"../runtime/types.h\"\nvoid RunScheduler();\n\n");

	fprintf(mainh, "#include \"../runtime/types.h\"\n");

	vecFunction* functions_arr = malloc(sizeof(vecFunction) * spritecount);

	int vars_count = 0;
	for (int i = 0; i < spritecount; i++)
	{
		struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "variables");

		json_object_object_foreach(vars, key, val)
		{
			AddVariable(AsManagedString(key), SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))), i);
			vars_count++;
		}
	}

	doublevar = malloc(vars_count); if (!doublevar) { printf("Malloc error!"); exit(-1); }

	for (int i = 0; i < vars_count; i++) 
	{
		doublevar[i] = true;
	}

	for (int i = 0; i < spritecount; i++) 
	{
		struct json_object* blocks = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "block");


	}

	int vc_2 = 0;

	for (int i = 0; i < spritecount; i++) 
	{
		struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "variables");
		
		json_object_object_foreach(vars, key, val)
		{
			if (doublevar[getVariableIndexById(AsManagedString(key))])
			{
				fprintf(output, "double %s;\n", getVariableNameById(AsManagedString(key)).data);
				vc_2++;
			}
			else
			{
				fprintf(output, "ScratchValue %s;\n", getVariableNameById(AsManagedString(key)).data);
			}
		}
	}

	if (vc_2)
	{
		fprintf(output, "\nScratchValue* vars[] = \n{");
		for (int i = 0; i < spritecount; i++)
		{
			struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "variables");

			json_object_object_foreach(vars, key, val)
			{
				if (doublevar[getVariableIndexById(AsManagedString(key))])
				{
					fprintf(output, "\t&%s,\n", getVariableNameById(AsManagedString(key)).data);
				}
			}
		}
		fprintf(output, "};\n\n");
	}
	else 
	{
		fprintf(output, "\nScratchValue* vars[] = { NULL };\n\n");
	}

	int lists_count = 0;
	for (int i = 0; i < spritecount; i++)
	{
		struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "lists");

		json_object_object_foreach(vars, key, val)
		{
			lists_count++;
		}
	}

	for (int i = 0; i < spritecount; i++)
	{
		struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "lists");

		json_object_object_foreach(vars, key, val)
		{
			fprintf(output, "ScratchList %s;\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data);
		}
	}
	if (lists_count)
	{
		fprintf(output, "\nScratchList* lists[] = \n{");
		for (int i = 0; i < spritecount; i++)
		{
			struct json_object* vars = json_object_object_get(json_object_array_get_idx(json_object_object_get(project, "targets"), i), "lists");

			json_object_object_foreach(vars, key, val)
			{
				fprintf(output, "\t&%s,\n", SanitiseScratchNameToC(AsManagedString(json_object_get_string(json_object_array_get_idx(val, 0)))).data);
			}
		}
		fprintf(output, "};\n\n");
	}
	else
	{
		fprintf(output, "\nScratchList* lists[] = { NULL };\n\n");
	}

	fprintf(output, "int vars_length = %i, lists_length = %i;\n", vc_2, lists_count);

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

		GetFullProgram(mainh, output, scheduler, vars, lists, functions, blocks, si);
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
	fprintf(scheduler, "\t\tfor (int i = 0; i < threads.length; i++)\n\t\t{\n\t\t\tactiveSprite = threads.data[i].index;\n\t\t\tco_switch(threads.data[i].thread);\n\t\t\tif (delete_thread) { RemoveThread(i); i--;  delete_thread = false; }\n");
	fprintf(scheduler, "\t\t\tif (stop_all) { while (threads.length) { RemoveThread(0); } stop_all = false; }\n");
	fprintf(scheduler, "\t\t\tif (stop_other) { cothread_t this = threads.data[i].thread; int this_index = threads.data[i].index; for (int i = 0; i < threads.length; i++) { if (threads.data[i].index == this_index && threads.data[i].thread != this) { RemoveThread(i--); } } stop_other = false; }\n");
	fprintf(scheduler, "\t\t}\n");

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
#define addkeysh(scancode, event) if (FunctionsPresent[j][event]){fprintf(scheduler, "\t\tif (keysdownheld[" #scancode "] == 1 && ( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))\n\t\t{\n");for (int i = 0; i < functions_arr[j].length; i++){if (functions_arr[j].data[i].opcode == event){fprintf(scheduler, "\t\t\tAddThread(THREAD(co_create(64 * 1024, %s),%i));\n", functions_arr[j].data[i].proccode.data, j);}}fprintf(scheduler, "\t\t}\n");}
#define addkeynosh(scancode, event) if (FunctionsPresent[j][event]){fprintf(scheduler, "\t\tif (keysdownheld[" #scancode "] == 1 && !( keysdown[SDL_SCANCODE_LSHIFT] == 1 || keysdown[SDL_SCANCODE_RSHIFT] == 1))\n\t\t{\n");for (int i = 0; i < functions_arr[j].length; i++){if (functions_arr[j].data[i].opcode == event){fprintf(scheduler, "\t\t\tAddThread(THREAD(co_create(64 * 1024, %s),%i));\n", functions_arr[j].data[i].proccode.data, j);}}fprintf(scheduler, "\t\t}\n");}
#define addkey2(scancode1, scancode2, event) if (FunctionsPresent[j][event]){fprintf(scheduler, "\t\tif (keysdownheld[" #scancode1 "] == 1 || keysdownheld[" #scancode2 "] == 1)\n\t\t{\n");for (int i = 0; i < functions_arr[j].length; i++){if (functions_arr[j].data[i].opcode == event){fprintf(scheduler, "\t\t\tAddThread(THREAD(co_create(64 * 1024, %s),%i));\n", functions_arr[j].data[i].proccode.data, j);}}fprintf(scheduler, "\t\t}\n");}

		addkey(SDL_SCANCODE_SPACE, event_whenkeypressed_space);
		addkey(SDL_SCANCODE_UP, event_whenkeypressed_up_arrow);
		addkey(SDL_SCANCODE_RIGHT, event_whenkeypressed_right_arrow);
		addkey(SDL_SCANCODE_LEFT, event_whenkeypressed_left_arrow);
		addkey(SDL_SCANCODE_DOWN, event_whenkeypressed_down_arrow);
		addkey(SDL_SCANCODE_RETURN, event_whenkeypressed_enter);

		addkey(SDL_SCANCODE_A, event_whenkeypressed_a);
		addkey(SDL_SCANCODE_B, event_whenkeypressed_b);
		addkey(SDL_SCANCODE_C, event_whenkeypressed_c);
		addkey(SDL_SCANCODE_D, event_whenkeypressed_d);
		addkey(SDL_SCANCODE_E, event_whenkeypressed_e);
		addkey(SDL_SCANCODE_F, event_whenkeypressed_f);
		addkey(SDL_SCANCODE_G, event_whenkeypressed_g);
		addkey(SDL_SCANCODE_H, event_whenkeypressed_h);
		addkey(SDL_SCANCODE_I, event_whenkeypressed_i);
		addkey(SDL_SCANCODE_J, event_whenkeypressed_j);
		addkey(SDL_SCANCODE_K, event_whenkeypressed_k);
		addkey(SDL_SCANCODE_L, event_whenkeypressed_l);
		addkey(SDL_SCANCODE_M, event_whenkeypressed_m);
		addkey(SDL_SCANCODE_N, event_whenkeypressed_n);
		addkey(SDL_SCANCODE_O, event_whenkeypressed_o);
		addkey(SDL_SCANCODE_P, event_whenkeypressed_p);
		addkey(SDL_SCANCODE_Q, event_whenkeypressed_q);
		addkey(SDL_SCANCODE_R, event_whenkeypressed_r);
		addkey(SDL_SCANCODE_S, event_whenkeypressed_s);
		addkey(SDL_SCANCODE_T, event_whenkeypressed_t);
		addkey(SDL_SCANCODE_U, event_whenkeypressed_u);
		addkey(SDL_SCANCODE_V, event_whenkeypressed_v);
		addkey(SDL_SCANCODE_W, event_whenkeypressed_w);
		addkey(SDL_SCANCODE_X, event_whenkeypressed_x);
		addkey(SDL_SCANCODE_Y, event_whenkeypressed_y);
		addkey(SDL_SCANCODE_Z, event_whenkeypressed_z);

		addkeynosh(SDL_SCANCODE_0, event_whenkeypressed_0);
		addkeynosh(SDL_SCANCODE_1, event_whenkeypressed_1);
		addkeynosh(SDL_SCANCODE_2, event_whenkeypressed_2);
		addkeynosh(SDL_SCANCODE_3, event_whenkeypressed_3);
		addkeynosh(SDL_SCANCODE_4, event_whenkeypressed_4);
		addkeynosh(SDL_SCANCODE_5, event_whenkeypressed_5);
		addkeynosh(SDL_SCANCODE_6, event_whenkeypressed_6);
		addkeynosh(SDL_SCANCODE_7, event_whenkeypressed_7);
		addkeynosh(SDL_SCANCODE_8, event_whenkeypressed_8);
		addkeynosh(SDL_SCANCODE_9, event_whenkeypressed_9);
		addkeynosh(SDL_SCANCODE_MINUS, event_whenkeypressed_minus);
		addkeynosh(SDL_SCANCODE_COMMA, event_whenkeypressed_comma);
		addkeynosh(SDL_SCANCODE_PERIOD, event_whenkeypressed_full_stop);
		addkeynosh(SDL_SCANCODE_GRAVE, event_whenkeypressed_back_tick);
		addkeynosh(SDL_SCANCODE_EQUALS, event_whenkeypressed_equals);
		addkeynosh(SDL_SCANCODE_LEFTBRACKET, event_whenkeypressed_left_bracket);
		addkeynosh(SDL_SCANCODE_RIGHTBRACKET, event_whenkeypressed_right_bracket);
		addkeynosh(SDL_SCANCODE_BACKSLASH, event_whenkeypressed_backslash);
		addkeynosh(SDL_SCANCODE_SEMICOLON, event_whenkeypressed_semicolon);
		addkeynosh(SDL_SCANCODE_APOSTROPHE, event_whenkeypressed_single_quote);
		addkeynosh(SDL_SCANCODE_SLASH, event_whenkeypressed_solidus);
		addkeysh(SDL_SCANCODE_0, event_whenkeypressed_exclamation_mark);
		addkeysh(SDL_SCANCODE_1, event_whenkeypressed_at_sign);
		addkeysh(SDL_SCANCODE_2, event_whenkeypressed_pound);
		addkeysh(SDL_SCANCODE_3, event_whenkeypressed_dollar);
		addkeysh(SDL_SCANCODE_4, event_whenkeypressed_percent);
		addkeysh(SDL_SCANCODE_5, event_whenkeypressed_caret);
		addkeysh(SDL_SCANCODE_6, event_whenkeypressed_ampersand);
		addkeysh(SDL_SCANCODE_7, event_whenkeypressed_star);
		addkeysh(SDL_SCANCODE_8, event_whenkeypressed_left_parenth);
		addkeysh(SDL_SCANCODE_9, event_whenkeypressed_right_parenth);
		addkeysh(SDL_SCANCODE_MINUS, event_whenkeypressed_underscore);
		addkeysh(SDL_SCANCODE_EQUALS, event_whenkeypressed_plus);
		addkeysh(SDL_SCANCODE_LEFTBRACKET, event_whenkeypressed_left_brace);
		addkeysh(SDL_SCANCODE_RIGHTBRACKET, event_whenkeypressed_right_brace);
		addkeysh(SDL_SCANCODE_BACKSLASH, event_whenkeypressed_pipe);
		addkeysh(SDL_SCANCODE_SEMICOLON, event_whenkeypressed_colon);
		addkeysh(SDL_SCANCODE_APOSTROPHE, event_whenkeypressed_double_quote);
		addkeysh(SDL_SCANCODE_SLASH, event_whenkeypressed_question_mark);
		addkeysh(SDL_SCANCODE_COMMA, event_whenkeypressed_left_triangle_bracket);
		addkeysh(SDL_SCANCODE_PERIOD, event_whenkeypressed_right_traingle_bracket);
		addkeysh(SDL_SCANCODE_GRAVE, event_whenkeypressed_tilda);

		addkey(SDL_SCANCODE_BACKSPACE, event_whenkeypressed_backspace);
		addkey(SDL_SCANCODE_DELETE, event_whenkeypressed_delete);
		addkey2(SDL_SCANCODE_LSHIFT, SDL_SCANCODE_RSHIFT, event_whenkeypressed_shift);
		addkey(SDL_SCANCODE_CAPSLOCK, event_whenkeypressed_caps_lock);
		addkey(SDL_SCANCODE_SCROLLLOCK, event_whenkeypressed_scroll_lock);
		addkey2(SDL_SCANCODE_LCTRL, SDL_SCANCODE_RCTRL,event_whenkeypressed_control);
		addkey(SDL_SCANCODE_ESCAPE, event_whenkeypressed_escape);
		addkey(SDL_SCANCODE_INSERT, event_whenkeypressed_insert);
		addkey(SDL_SCANCODE_HOME, event_whenkeypressed_home);
		addkey(SDL_SCANCODE_END, event_whenkeypressed_end);
		addkey(SDL_SCANCODE_PAGEUP, event_whenkeypressed_page_up);
		addkey(SDL_SCANCODE_PAGEDOWN, event_whenkeypressed_page_down);

#undef addkey()
#undef addkeysh()
#undef addkeynosh()
#undef addkey2()
	}
	fprintf(scheduler, "\t\tRender();\n\t}\n}\n");

	initialiseBroadcasts();

	for (int j = 0; j < spritecount; j++)
	{
		if (FunctionsPresent[j][event_whenbroadcastreceived])
		{
			for (int i = 0; i < functions_arr[j].length; i++)
			{
				if (functions_arr[j].data[i].opcode == event_whenbroadcastreceived)
				{
					if (!broadcastsContains(functions_arr[j].data[i].argids[0].data))
					{
						fprintf(scheduler, "BroadcastInfo broadcast_%s()\n{\n", functions_arr[j].data[i].argids[0].data);
						fprintf(schedulerh, "BroadcastInfo broadcast_%s();\n", functions_arr[j].data[i].argids[0].data);
						int length = 0;
						for (int j1 = 0; j1 < spritecount; j1++)
						{
							if (FunctionsPresent[j][event_whenbroadcastreceived])
							{
								for (int i1 = 0; i1 < functions_arr[j1].length; i1++)
								{
									if (functions_arr[j1].data[i1].opcode == event_whenbroadcastreceived)
									{
										if (strcmp(functions_arr[j].data[i].argids[0].data, functions_arr[j1].data[i1].argids[0].data) == 0)
										{
											length++;
										}
									}
								}
							}
						}
						fprintf(scheduler, "\tThread* output = malloc(sizeof(Thread)* %i);\n", length);
						int cnt = 0;
						for (int j1 = 0; j1 < spritecount; j1++)
						{
							if (FunctionsPresent[j][event_whenbroadcastreceived])
							{
								for (int i1 = 0; i1 < functions_arr[j1].length; i1++)
								{
									if (functions_arr[j1].data[i1].opcode == event_whenbroadcastreceived)
									{
										if (strcmp(functions_arr[j].data[i].argids[0].data, functions_arr[j1].data[i1].argids[0].data) == 0)
										{
											fprintf(scheduler, "\toutput[%i] = THREAD(co_create(64 * 1024, %s),1); AddThread(output[%i]);\n", cnt, functions_arr[j1].data[i1].proccode.data, cnt);
											cnt++;
										}
									}
								}
							}
						}
						addToBroadcasts(functions_arr[j].data[i].argids[0].data);
						fprintf(scheduler, "\treturn (BroadcastInfo) {output, %i};\n}\n",length);
					}
				}
			}
		}
	}

	fclose(mainh);
	fclose(output);
	fclose(scheduler);

	return 0;
}