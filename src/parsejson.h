typedef struct ParseTextReturn 
{
	vecScratchBlock blocks;
	vecFunction functions;
} ParseTextReturn;

struct ParseTextReturn ParseText(struct json_object* blocks);
int GetIndexOfBlockById(char* id, vecScratchBlock lines);