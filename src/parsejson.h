vecFunction ParseText(struct json_object* blocks);
int GetIndexOfBlockById(char* id, vecScratchBlock lines);
ScratchBlock GetBlock(const char* id, struct json_object* blocks);