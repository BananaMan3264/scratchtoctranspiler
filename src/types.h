enum ArgTypes
{
	ArgType_Pointer = 3,
	ArgType_Number = 4,			// Number		   | All of these act the same way. They are only seperate for the purpose of the editor.
	ArgType_PositiveNumber = 5,	// Positive Number |
	ArgType_NegativeNumber = 6,	// Negative Number | 
	ArgType_Integer = 7,		// Integer		   | 
	ArgType_Angle = 8,			// Angle		   | 

	ArgType_String = 10,	// Text
};

typedef struct String
{
	bool managed; // True if the string should not be freed.
	char* data;
} String;

typedef union ScratchArgData
{
	String idPointer;
	String text;
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