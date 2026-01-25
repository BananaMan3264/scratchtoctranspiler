enum ArgTypes
{
	ArgType_Pointer = 3,
	ArgType_Text = 4,
	ArgType_Number = 5,
	ArgType_Number1 = 6,	// Positive number | These two are Scratch jankness; they
	ArgType_Number2 = 7,	// Angle		   | work the same way as ArgType_Number
};

typedef struct String
{
	bool managed; // True if the string should not be freed (Managed by json-c)
	char* data;
} String;

typedef union ScratchArgData
{
	String idPointer;
	String text;
	double number;
} ScratchArgData;

typedef struct ScratchBlock
{
	String id;
	String opcode;
	String next;
	String previous;
	int args;
	int* argtypes;
	ScratchArgData* argdata;
} ScratchBlock;

typedef struct vecScratchBlock {
	ScratchBlock* data; size_t allocated_size; size_t length; size_t sizeoftype;
} vecScratchBlock;

#define AsUnmanagedString(a) (String){false, a}
#define AsManagedString(a)   (String){true,  a}

#define freeIfUnmanaged(a) if(!a.managed) { free(a.data); }