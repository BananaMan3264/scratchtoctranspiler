String LineToBlock(ScratchBlock sb, struct json_object* blocks, bool top);
void PrintData(struct json_object* targets);
int GetFirstWhenFlagClicked(vecScratchBlock lines);
char* GetFullProgram(struct json_object* variables, vecFunction functions, struct json_object* blocks);