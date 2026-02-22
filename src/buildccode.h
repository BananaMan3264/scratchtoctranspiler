#include"types.h"
void PrintData(struct json_object* targets);
int GetFirstWhenFlagClicked(vecScratchBlock lines);
char* GetFullProgram(FILE* header_file, FILE* source_file, FILE* scheduler, struct json_object* variables, struct json_object* lists, vecFunction functions, struct json_object* blocks, int working_index);
typedef struct return_vals
{
	String double_return;
	String string_return;
	String bool_return;
	String scratch_return;
} return_vals;
return_vals LineToBlock(ScratchBlock sb, struct json_object* blocks, bool top);
return_vals GetArg(int argtype, ScratchArgData argdata, struct json_object* blocks);