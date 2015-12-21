#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 11 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# syntaxAnalyzer.v
# YACC verbose file generated from syntaxAnalyzer.y.
# 
# Date: 12/16/15
# Time: 21:53:01
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : prog $end

    1  prog : partProg

    2  partProg : sentence
    3           | constDec sentence
    4           | constDec varDec sentence
    5           | constDec varDec proDec sentence

    6  constDec : CONST constDef moreConstDef SEMICOLON

    7  moreConstDef : COMMA constDef
    8               | COMMA constDef moreConstDef
    9               |

   10  constDef : IDENTIFIER '=' UINT

   11  varDec : VAR IDENTIFIER moreIdentifier SEMICOLON

   12  moreIdentifier : COMMA IDENTIFIER
   13                 | COMMA IDENTIFIER moreIdentifier
   14                 |

   15  proDec : proHead partProg moreProDec SEMICOLON

   16  proHead : PROCEDURE IDENTIFIER SEMICOLON

   17  moreProDec : SEMICOLON proDec
   18             | SEMICOLON proDec moreProDec
   19             |

   20  sentence : assignSen
   21           | conditionSen
   22           | whileSen
   23           | proCallSen
   24           | reuniteSen
   25           | readSen
   26           | writeSen
   27           |

   28  assignSen : IDENTIFIER ASSIGN expr

   29  expr : item moreItem
   30       | '+' item moreItem
   31       | '-' item moreItem

   32  moreItem : ADDOPERATOR item
   33           | ADDOPERATOR item moreItem
   34           |

   35  item : factor moreFactor

   36  factor : IDENTIFIER
   37         | UINT
   38         | LP expr RP

   39  moreFactor : MULOPERATOR factor
   40             | MULOPERATOR factor moreFactor
   41             |

   42  condition : expr RELOPERATOR expr
   43            | ODD expr

   44  conditionSen : IF condition THEN sentence

   45  whileSen : WHILE condition DO sentence

   46  proCallSen : CALL IDENTIFIER

   47  reuniteSen : BEGIN sentence moreSentence END

   48  moreSentence : SEMICOLON sentence
   49               | SEMICOLON sentence moreSentence
   50               |

   51  readSen : READ LP IDENTIFIER moreIdentifier RP

   52  writeSen : WRITE LP expr moreExpr RP

   53  moreExpr : COMMA expr
   54           | COMMA expr moreExpr
   55           |


##############################################################################
# States
##############################################################################

state 0
	$accept : . prog $end
	sentence : .  (27)

	IDENTIFIER  shift 1
	CONST  shift 2
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	partProg  goto 9
	constDec  goto 10
	prog  goto 11
	sentence  goto 12
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 1
	assignSen : IDENTIFIER . ASSIGN expr

	ASSIGN  shift 20


state 2
	constDec : CONST . constDef moreConstDef SEMICOLON

	IDENTIFIER  shift 21

	constDef  goto 22


state 3
	conditionSen : IF . condition THEN sentence

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	ODD  shift 27
	LP  shift 28

	expr  goto 29
	item  goto 30
	factor  goto 31
	condition  goto 32


state 4
	whileSen : WHILE . condition DO sentence

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	ODD  shift 27
	LP  shift 28

	expr  goto 29
	item  goto 30
	factor  goto 31
	condition  goto 33


state 5
	proCallSen : CALL . IDENTIFIER

	IDENTIFIER  shift 34


state 6
	reuniteSen : BEGIN . sentence moreSentence END
	sentence : .  (27)

	IDENTIFIER  shift 1
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	sentence  goto 35
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 7
	readSen : READ . LP IDENTIFIER moreIdentifier RP

	LP  shift 36


state 8
	writeSen : WRITE . LP expr moreExpr RP

	LP  shift 37


state 9
	prog : partProg .  (1)

	.  reduce 1


state 10
	partProg : constDec . sentence
	partProg : constDec . varDec sentence
	partProg : constDec . varDec proDec sentence
	sentence : .  (27)

	IDENTIFIER  shift 1
	VAR  shift 38
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	varDec  goto 39
	sentence  goto 40
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 11
	$accept : prog . $end  (0)

	$end  accept


state 12
	partProg : sentence .  (2)

	.  reduce 2


state 13
	sentence : reuniteSen .  (24)

	.  reduce 24


state 14
	sentence : readSen .  (25)

	.  reduce 25


state 15
	sentence : assignSen .  (20)

	.  reduce 20


state 16
	sentence : proCallSen .  (23)

	.  reduce 23


state 17
	sentence : conditionSen .  (21)

	.  reduce 21


state 18
	sentence : writeSen .  (26)

	.  reduce 26


state 19
	sentence : whileSen .  (22)

	.  reduce 22


state 20
	assignSen : IDENTIFIER ASSIGN . expr

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	expr  goto 41
	item  goto 30
	factor  goto 31


state 21
	constDef : IDENTIFIER . '=' UINT

	'='  shift 42


state 22
	constDec : CONST constDef . moreConstDef SEMICOLON
	moreConstDef : .  (9)

	COMMA  shift 43
	.  reduce 9

	moreConstDef  goto 44


state 23
	expr : '+' . item moreItem

	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	item  goto 45
	factor  goto 31


state 24
	expr : '-' . item moreItem

	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	item  goto 46
	factor  goto 31


state 25
	factor : IDENTIFIER .  (36)

	.  reduce 36


state 26
	factor : UINT .  (37)

	.  reduce 37


state 27
	condition : ODD . expr

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	expr  goto 47
	item  goto 30
	factor  goto 31


state 28
	factor : LP . expr RP

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	expr  goto 48
	item  goto 30
	factor  goto 31


state 29
	condition : expr . RELOPERATOR expr

	RELOPERATOR  shift 49


state 30
	expr : item . moreItem
	moreItem : .  (34)

	ADDOPERATOR  shift 50
	.  reduce 34

	moreItem  goto 51


state 31
	item : factor . moreFactor
	moreFactor : .  (41)

	MULOPERATOR  shift 52
	.  reduce 41

	moreFactor  goto 53


state 32
	conditionSen : IF condition . THEN sentence

	THEN  shift 54


state 33
	whileSen : WHILE condition . DO sentence

	DO  shift 55


state 34
	proCallSen : CALL IDENTIFIER .  (46)

	.  reduce 46


state 35
	reuniteSen : BEGIN sentence . moreSentence END
	moreSentence : .  (50)

	SEMICOLON  shift 56
	.  reduce 50

	moreSentence  goto 57


state 36
	readSen : READ LP . IDENTIFIER moreIdentifier RP

	IDENTIFIER  shift 58


state 37
	writeSen : WRITE LP . expr moreExpr RP

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	expr  goto 59
	item  goto 30
	factor  goto 31


state 38
	varDec : VAR . IDENTIFIER moreIdentifier SEMICOLON

	IDENTIFIER  shift 60


state 39
	partProg : constDec varDec . sentence
	partProg : constDec varDec . proDec sentence
	sentence : .  (27)

	IDENTIFIER  shift 1
	PROCEDURE  shift 61
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	proDec  goto 62
	proHead  goto 63
	sentence  goto 64
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 40
	partProg : constDec sentence .  (3)

	.  reduce 3


state 41
	assignSen : IDENTIFIER ASSIGN expr .  (28)

	.  reduce 28


state 42
	constDef : IDENTIFIER '=' . UINT

	UINT  shift 65


state 43
	moreConstDef : COMMA . constDef
	moreConstDef : COMMA . constDef moreConstDef

	IDENTIFIER  shift 21

	constDef  goto 66


state 44
	constDec : CONST constDef moreConstDef . SEMICOLON

	SEMICOLON  shift 67


state 45
	expr : '+' item . moreItem
	moreItem : .  (34)

	ADDOPERATOR  shift 50
	.  reduce 34

	moreItem  goto 68


state 46
	expr : '-' item . moreItem
	moreItem : .  (34)

	ADDOPERATOR  shift 50
	.  reduce 34

	moreItem  goto 69


state 47
	condition : ODD expr .  (43)

	.  reduce 43


state 48
	factor : LP expr . RP

	RP  shift 70


state 49
	condition : expr RELOPERATOR . expr

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	expr  goto 71
	item  goto 30
	factor  goto 31


state 50
	moreItem : ADDOPERATOR . item
	moreItem : ADDOPERATOR . item moreItem

	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	item  goto 72
	factor  goto 31


state 51
	expr : item moreItem .  (29)

	.  reduce 29


state 52
	moreFactor : MULOPERATOR . factor moreFactor
	moreFactor : MULOPERATOR . factor

	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	factor  goto 73


state 53
	item : factor moreFactor .  (35)

	.  reduce 35


state 54
	conditionSen : IF condition THEN . sentence
	sentence : .  (27)

	IDENTIFIER  shift 1
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	sentence  goto 74
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 55
	whileSen : WHILE condition DO . sentence
	sentence : .  (27)

	IDENTIFIER  shift 1
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	sentence  goto 75
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 56
	moreSentence : SEMICOLON . sentence moreSentence
	moreSentence : SEMICOLON . sentence
	sentence : .  (27)

	IDENTIFIER  shift 1
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	sentence  goto 76
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 57
	reuniteSen : BEGIN sentence moreSentence . END

	END  shift 77


state 58
	readSen : READ LP IDENTIFIER . moreIdentifier RP
	moreIdentifier : .  (14)

	COMMA  shift 78
	.  reduce 14

	moreIdentifier  goto 79


state 59
	writeSen : WRITE LP expr . moreExpr RP
	moreExpr : .  (55)

	COMMA  shift 80
	.  reduce 55

	moreExpr  goto 81


state 60
	varDec : VAR IDENTIFIER . moreIdentifier SEMICOLON
	moreIdentifier : .  (14)

	COMMA  shift 78
	.  reduce 14

	moreIdentifier  goto 82


state 61
	proHead : PROCEDURE . IDENTIFIER SEMICOLON

	IDENTIFIER  shift 83


state 62
	partProg : constDec varDec proDec . sentence
	sentence : .  (27)

	IDENTIFIER  shift 1
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	sentence  goto 84
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 63
	proDec : proHead . partProg moreProDec SEMICOLON
	sentence : .  (27)

	IDENTIFIER  shift 1
	CONST  shift 2
	IF  shift 3
	WHILE  shift 4
	CALL  shift 5
	BEGIN  shift 6
	READ  shift 7
	WRITE  shift 8
	.  reduce 27

	partProg  goto 85
	constDec  goto 10
	sentence  goto 12
	reuniteSen  goto 13
	readSen  goto 14
	assignSen  goto 15
	proCallSen  goto 16
	conditionSen  goto 17
	writeSen  goto 18
	whileSen  goto 19


state 64
	partProg : constDec varDec sentence .  (4)

	.  reduce 4


state 65
	constDef : IDENTIFIER '=' UINT .  (10)

	.  reduce 10


66: reduce-reduce conflict (reduce 7, reduce 9) on SEMICOLON
state 66
	moreConstDef : COMMA constDef .  (7)
	moreConstDef : COMMA constDef . moreConstDef
	moreConstDef : .  (9)

	COMMA  shift 43
	.  reduce 7

	moreConstDef  goto 86


state 67
	constDec : CONST constDef moreConstDef SEMICOLON .  (6)

	.  reduce 6


state 68
	expr : '+' item moreItem .  (30)

	.  reduce 30


state 69
	expr : '-' item moreItem .  (31)

	.  reduce 31


state 70
	factor : LP expr RP .  (38)

	.  reduce 38


state 71
	condition : expr RELOPERATOR expr .  (42)

	.  reduce 42


72: reduce-reduce conflict (reduce 32, reduce 34) on $end
72: reduce-reduce conflict (reduce 32, reduce 34) on RELOPERATOR
72: reduce-reduce conflict (reduce 32, reduce 34) on THEN
72: reduce-reduce conflict (reduce 32, reduce 34) on DO
72: reduce-reduce conflict (reduce 32, reduce 34) on END
72: reduce-reduce conflict (reduce 32, reduce 34) on COMMA
72: reduce-reduce conflict (reduce 32, reduce 34) on SEMICOLON
72: reduce-reduce conflict (reduce 32, reduce 34) on RP
state 72
	moreItem : ADDOPERATOR item .  (32)
	moreItem : ADDOPERATOR item . moreItem
	moreItem : .  (34)

	ADDOPERATOR  shift 50
	.  reduce 32

	moreItem  goto 87


73: reduce-reduce conflict (reduce 39, reduce 41) on $end
73: reduce-reduce conflict (reduce 39, reduce 41) on ADDOPERATOR
73: reduce-reduce conflict (reduce 39, reduce 41) on RELOPERATOR
73: reduce-reduce conflict (reduce 39, reduce 41) on THEN
73: reduce-reduce conflict (reduce 39, reduce 41) on DO
73: reduce-reduce conflict (reduce 39, reduce 41) on END
73: reduce-reduce conflict (reduce 39, reduce 41) on COMMA
73: reduce-reduce conflict (reduce 39, reduce 41) on SEMICOLON
73: reduce-reduce conflict (reduce 39, reduce 41) on RP
state 73
	moreFactor : MULOPERATOR factor . moreFactor
	moreFactor : MULOPERATOR factor .  (39)
	moreFactor : .  (41)

	MULOPERATOR  shift 52
	.  reduce 39

	moreFactor  goto 88


state 74
	conditionSen : IF condition THEN sentence .  (44)

	.  reduce 44


state 75
	whileSen : WHILE condition DO sentence .  (45)

	.  reduce 45


76: reduce-reduce conflict (reduce 48, reduce 50) on END
state 76
	moreSentence : SEMICOLON sentence . moreSentence
	moreSentence : SEMICOLON sentence .  (48)
	moreSentence : .  (50)

	SEMICOLON  shift 56
	.  reduce 48

	moreSentence  goto 89


state 77
	reuniteSen : BEGIN sentence moreSentence END .  (47)

	.  reduce 47


state 78
	moreIdentifier : COMMA . IDENTIFIER
	moreIdentifier : COMMA . IDENTIFIER moreIdentifier

	IDENTIFIER  shift 90


state 79
	readSen : READ LP IDENTIFIER moreIdentifier . RP

	RP  shift 91


state 80
	moreExpr : COMMA . expr moreExpr
	moreExpr : COMMA . expr

	'+'  shift 23
	'-'  shift 24
	IDENTIFIER  shift 25
	UINT  shift 26
	LP  shift 28

	expr  goto 92
	item  goto 30
	factor  goto 31


state 81
	writeSen : WRITE LP expr moreExpr . RP

	RP  shift 93


state 82
	varDec : VAR IDENTIFIER moreIdentifier . SEMICOLON

	SEMICOLON  shift 94


state 83
	proHead : PROCEDURE IDENTIFIER . SEMICOLON

	SEMICOLON  shift 95


state 84
	partProg : constDec varDec proDec sentence .  (5)

	.  reduce 5


85: shift-reduce conflict (shift 96, reduce 19) on SEMICOLON
state 85
	proDec : proHead partProg . moreProDec SEMICOLON
	moreProDec : .  (19)

	SEMICOLON  shift 96

	moreProDec  goto 97


state 86
	moreConstDef : COMMA constDef moreConstDef .  (8)

	.  reduce 8


state 87
	moreItem : ADDOPERATOR item moreItem .  (33)

	.  reduce 33


state 88
	moreFactor : MULOPERATOR factor moreFactor .  (40)

	.  reduce 40


state 89
	moreSentence : SEMICOLON sentence moreSentence .  (49)

	.  reduce 49


90: reduce-reduce conflict (reduce 12, reduce 14) on SEMICOLON
90: reduce-reduce conflict (reduce 12, reduce 14) on RP
state 90
	moreIdentifier : COMMA IDENTIFIER .  (12)
	moreIdentifier : COMMA IDENTIFIER . moreIdentifier
	moreIdentifier : .  (14)

	COMMA  shift 78
	.  reduce 12

	moreIdentifier  goto 98


state 91
	readSen : READ LP IDENTIFIER moreIdentifier RP .  (51)

	.  reduce 51


92: reduce-reduce conflict (reduce 53, reduce 55) on RP
state 92
	moreExpr : COMMA expr . moreExpr
	moreExpr : COMMA expr .  (53)
	moreExpr : .  (55)

	COMMA  shift 80
	.  reduce 53

	moreExpr  goto 99


state 93
	writeSen : WRITE LP expr moreExpr RP .  (52)

	.  reduce 52


state 94
	varDec : VAR IDENTIFIER moreIdentifier SEMICOLON .  (11)

	.  reduce 11


state 95
	proHead : PROCEDURE IDENTIFIER SEMICOLON .  (16)

	.  reduce 16


state 96
	moreProDec : SEMICOLON . proDec moreProDec
	moreProDec : SEMICOLON . proDec

	PROCEDURE  shift 61

	proDec  goto 100
	proHead  goto 63


state 97
	proDec : proHead partProg moreProDec . SEMICOLON

	SEMICOLON  shift 101


state 98
	moreIdentifier : COMMA IDENTIFIER moreIdentifier .  (13)

	.  reduce 13


state 99
	moreExpr : COMMA expr moreExpr .  (54)

	.  reduce 54


100: shift-reduce conflict (shift 96, reduce 19) on SEMICOLON
100: shift-reduce conflict (shift 96, reduce 17) on SEMICOLON
state 100
	moreProDec : SEMICOLON proDec . moreProDec
	moreProDec : SEMICOLON proDec .  (17)
	moreProDec : .  (19)

	SEMICOLON  shift 96

	moreProDec  goto 102


state 101
	proDec : proHead partProg moreProDec SEMICOLON .  (15)

	.  reduce 15


state 102
	moreProDec : SEMICOLON proDec moreProDec .  (18)

	.  reduce 18


Rules never reduced
	moreProDec : SEMICOLON proDec  (17)
	moreProDec :  (19)


Symbols never pushed
	proDec  (8)
	moreProDec  (10)


##############################################################################
# Summary
##############################################################################

State 66 contains 1 reduce-reduce conflict(s)
State 72 contains 8 reduce-reduce conflict(s)
State 73 contains 9 reduce-reduce conflict(s)
State 76 contains 1 reduce-reduce conflict(s)
State 85 contains 1 shift-reduce conflict(s)
State 90 contains 2 reduce-reduce conflict(s)
State 92 contains 1 reduce-reduce conflict(s)
State 100 contains 2 shift-reduce conflict(s)


28 token(s), 27 nonterminal(s)
56 grammar rule(s), 104 state(s)


##############################################################################
# End of File
##############################################################################
