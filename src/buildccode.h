String LineToBlock(int index, vecScratchBlock lines, bool top);
int GetFirstWhenFlagClicked(vecScratchBlock lines);
char* GetFullProgram(vecScratchBlock lines, struct json_object* variables, vecFunction functions);