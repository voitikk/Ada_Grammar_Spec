#define IS 257
#define BEG 258
#define END 259
#define PROCEDURE 260
#define ID 261
#define NUMBER 262
#define TYPE 263
#define ARRAY 264
#define RAISE 265
#define OTHERS 266
#define RECORD 267
#define IN 268
#define OUT 269
#define RANGE 270
#define CONSTANT 271
#define ASSIGN 272
#define EXCEPTION 273
#define NULLWORD 274
#define LOOP 275
#define IF 276
#define THEN 277
#define ELSEIF 278
#define ELSE 279
#define EXIT 280
#define WHEN 281
#define AND 282
#define OR 283
#define EQ 284
#define NEQ 285
#define LT 286
#define GT 287
#define GTE 288
#define LTE 289
#define TICK 290
#define NOT 291
#define EXP 292
#define ARROW 293
#define OF 294
#define DOTDOT 295
#define ENDIF 296
#define ENDREC 297
#define ENDLOOP 298
#define EXITWHEN 299
typedef union {
    	int integer;
    	char *var;
    	struct idnode *listptr;
		struct semInfo *semNode;
		struct writeNode *writeList;
} YYSTYPE;
extern YYSTYPE yylval;
