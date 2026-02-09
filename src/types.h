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

enum FunctionEvents
{
	event_whenflagclicked,
	event_whenkeypressed_a,
	event_whenkeypressed_b,
	event_whenkeypressed_c,
	event_whenkeypressed_d,
	event_whenkeypressed_e,
	event_whenkeypressed_f,
	event_whenkeypressed_g,
	event_whenkeypressed_h,
	event_whenkeypressed_i,
	event_whenkeypressed_j,
	event_whenkeypressed_k,
	event_whenkeypressed_l,
	event_whenkeypressed_m,
	event_whenkeypressed_n,
	event_whenkeypressed_o,
	event_whenkeypressed_p,
	event_whenkeypressed_q,
	event_whenkeypressed_r,
	event_whenkeypressed_s,
	event_whenkeypressed_t,
	event_whenkeypressed_u,
	event_whenkeypressed_v,
	event_whenkeypressed_w,
	event_whenkeypressed_x,
	event_whenkeypressed_y,
	event_whenkeypressed_z,

	event_whenkeypressed_0,
	event_whenkeypressed_1,
	event_whenkeypressed_2,
	event_whenkeypressed_3,
	event_whenkeypressed_4,
	event_whenkeypressed_5,
	event_whenkeypressed_6,
	event_whenkeypressed_7,
	event_whenkeypressed_8,
	event_whenkeypressed_9,

	procedures_prototype,

	FunctionEventsLength
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
	int opcode;
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