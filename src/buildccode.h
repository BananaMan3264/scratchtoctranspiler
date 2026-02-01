String LineToBlock(int index, vecScratchBlock lines, bool top);
int GetFirstWhenFlagClicked(vecScratchBlock lines);
char* GetFullProgram(struct json_object* variables, vecFunction functions, struct json_object* blocks);