enum ArgTypes
{
	ArgType_Pointer = 3,
	ArgType_Number = 4,			// Number		   | All of these act the same way. They are only seperate for the purpose of the editor.
	ArgType_PositiveNumber = 5,	// Positive Number |
	ArgType_NegativeNumber = 6,	// Negative Number | 
	ArgType_Integer = 7,		// Integer		   | 
	ArgType_Angle = 8,			// Angle		   | 

	ArgType_Colour = 9,			// Angle		   | 

	ArgType_String = 10,		// String

	ArgType_Variable = 12,		// Variable
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
	String opcode;
	int args;
	int* argtypes;
	ScratchArgData* argdata;
} ScratchBlock;

typedef struct vecScratchBlock {
	ScratchBlock* data; size_t allocated_size; size_t length; size_t sizeoftype;
} vecScratchBlock;

typedef struct Function 
{
	String proccode;
	int args;
	String next;
	char* argTypes;
	String* argids;
	vecScratchBlock blocks;
	bool warp;
} Function;

typedef struct vecFunction {
	Function* data; size_t allocated_size; size_t length; size_t sizeoftype;
} vecFunction;

#define AsUnmanagedString(a) (String){false, (char *)(a)}
#define AsManagedString(a)   (String){true,  (char *)(a)}

#define freeIfUnmanaged(a) if(!a.managed) { free(a.data); }