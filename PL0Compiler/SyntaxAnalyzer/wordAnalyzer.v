#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 10 of your 30 day trial period.
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
# wordAnalyzer.v
# Lex verbose file generated from wordAnalyzer.l.
# 
# Date: 12/16/15
# Time: 21:21:59
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [0-9]+

    2  [\+\-]

    3  [\*\/]

    4  ["="| "<>" | "<" | "<=" | ">" | ">="]

    5  [ \t\n]+

    6  const

    7  var

    8  procedure

    9  odd

   10  if

   11  then

   12  while

   13  do

   14  call

   15  begin

   16  end

   17  read

   18  write

   19  [a-z]([a-z]|[0-9])*

   20  ","

   21  ";"

   22  ":="

   23  "("

   24  ")"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x0009 - 0x000a (2)      goto 3
	0x0020                   goto 4
	0x0022                   goto 5
	0x0028                   goto 6
	0x0029                   goto 7
	0x002a                   goto 8
	0x002b                   goto 9
	0x002c                   goto 10
	0x002d                   goto 9
	0x002f                   goto 8
	0x0030 - 0x0039 (10)     goto 11
	0x003a                   goto 12
	0x003b                   goto 13
	0x003c - 0x003e (3)      goto 5
	0x0061                   goto 14
	0x0062                   goto 15
	0x0063                   goto 16
	0x0064                   goto 17
	0x0065                   goto 18
	0x0066 - 0x0068 (3)      goto 14
	0x0069                   goto 19
	0x006a - 0x006e (5)      goto 14
	0x006f                   goto 20
	0x0070                   goto 21
	0x0071                   goto 14
	0x0072                   goto 22
	0x0073                   goto 14
	0x0074                   goto 23
	0x0075                   goto 14
	0x0076                   goto 24
	0x0077                   goto 25
	0x0078 - 0x007a (3)      goto 14
	0x007c                   goto 5


state 2
	^INITIAL

	0x0009 - 0x000a (2)      goto 3
	0x0020                   goto 4
	0x0022                   goto 5
	0x0028                   goto 6
	0x0029                   goto 7
	0x002a                   goto 8
	0x002b                   goto 9
	0x002c                   goto 10
	0x002d                   goto 9
	0x002f                   goto 8
	0x0030 - 0x0039 (10)     goto 11
	0x003a                   goto 12
	0x003b                   goto 13
	0x003c - 0x003e (3)      goto 5
	0x0061                   goto 14
	0x0062                   goto 15
	0x0063                   goto 16
	0x0064                   goto 17
	0x0065                   goto 18
	0x0066 - 0x0068 (3)      goto 14
	0x0069                   goto 19
	0x006a - 0x006e (5)      goto 14
	0x006f                   goto 20
	0x0070                   goto 21
	0x0071                   goto 14
	0x0072                   goto 22
	0x0073                   goto 14
	0x0074                   goto 23
	0x0075                   goto 14
	0x0076                   goto 24
	0x0077                   goto 25
	0x0078 - 0x007a (3)      goto 14
	0x007c                   goto 5


state 3
	0x0009 - 0x000a (2)      goto 3
	0x0020                   goto 3

	match 5


state 4
	0x0009 - 0x000a (2)      goto 3
	0x0020                   goto 3

	match 4


state 5
	match 4


state 6
	match 23


state 7
	match 24


state 8
	match 3


state 9
	match 2


state 10
	match 20


state 11
	0x0030 - 0x0039 (10)     goto 11

	match 1


state 12
	0x003d                   goto 26


state 13
	match 21


state 14
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 19


state 15
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 27
	0x0066 - 0x007a (21)     goto 14

	match 19


state 16
	0x0030 - 0x0039 (10)     goto 14
	0x0061                   goto 28
	0x0062 - 0x006e (13)     goto 14
	0x006f                   goto 29
	0x0070 - 0x007a (11)     goto 14

	match 19


state 17
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006e (14)     goto 14
	0x006f                   goto 30
	0x0070 - 0x007a (11)     goto 14

	match 19


state 18
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006d (13)     goto 14
	0x006e                   goto 31
	0x006f - 0x007a (12)     goto 14

	match 19


state 19
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0065 (5)      goto 14
	0x0066                   goto 32
	0x0067 - 0x007a (20)     goto 14

	match 19


state 20
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0063 (3)      goto 14
	0x0064                   goto 33
	0x0065 - 0x007a (22)     goto 14

	match 19


state 21
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0071 (17)     goto 14
	0x0072                   goto 34
	0x0073 - 0x007a (8)      goto 14

	match 19


state 22
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 35
	0x0066 - 0x007a (21)     goto 14

	match 19


state 23
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0067 (7)      goto 14
	0x0068                   goto 36
	0x0069 - 0x007a (18)     goto 14

	match 19


state 24
	0x0030 - 0x0039 (10)     goto 14
	0x0061                   goto 37
	0x0062 - 0x007a (25)     goto 14

	match 19


state 25
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0067 (7)      goto 14
	0x0068                   goto 38
	0x0069 - 0x0071 (9)      goto 14
	0x0072                   goto 39
	0x0073 - 0x007a (8)      goto 14

	match 19


state 26
	match 22


state 27
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0066 (6)      goto 14
	0x0067                   goto 40
	0x0068 - 0x007a (19)     goto 14

	match 19


state 28
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006b (11)     goto 14
	0x006c                   goto 41
	0x006d - 0x007a (14)     goto 14

	match 19


state 29
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006d (13)     goto 14
	0x006e                   goto 42
	0x006f - 0x007a (12)     goto 14

	match 19


state 30
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 13


state 31
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0063 (3)      goto 14
	0x0064                   goto 43
	0x0065 - 0x007a (22)     goto 14

	match 19


state 32
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 10


state 33
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0063 (3)      goto 14
	0x0064                   goto 44
	0x0065 - 0x007a (22)     goto 14

	match 19


state 34
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006e (14)     goto 14
	0x006f                   goto 45
	0x0070 - 0x007a (11)     goto 14

	match 19


state 35
	0x0030 - 0x0039 (10)     goto 14
	0x0061                   goto 46
	0x0062 - 0x007a (25)     goto 14

	match 19


state 36
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 47
	0x0066 - 0x007a (21)     goto 14

	match 19


state 37
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0071 (17)     goto 14
	0x0072                   goto 48
	0x0073 - 0x007a (8)      goto 14

	match 19


state 38
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0068 (8)      goto 14
	0x0069                   goto 49
	0x006a - 0x007a (17)     goto 14

	match 19


state 39
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0068 (8)      goto 14
	0x0069                   goto 50
	0x006a - 0x007a (17)     goto 14

	match 19


state 40
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0068 (8)      goto 14
	0x0069                   goto 51
	0x006a - 0x007a (17)     goto 14

	match 19


state 41
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006b (11)     goto 14
	0x006c                   goto 52
	0x006d - 0x007a (14)     goto 14

	match 19


state 42
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0072 (18)     goto 14
	0x0073                   goto 53
	0x0074 - 0x007a (7)      goto 14

	match 19


state 43
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 16


state 44
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 9


state 45
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0062 (2)      goto 14
	0x0063                   goto 54
	0x0064 - 0x007a (23)     goto 14

	match 19


state 46
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0063 (3)      goto 14
	0x0064                   goto 55
	0x0065 - 0x007a (22)     goto 14

	match 19


state 47
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006d (13)     goto 14
	0x006e                   goto 56
	0x006f - 0x007a (12)     goto 14

	match 19


state 48
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 7


state 49
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006b (11)     goto 14
	0x006c                   goto 57
	0x006d - 0x007a (14)     goto 14

	match 19


state 50
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0073 (19)     goto 14
	0x0074                   goto 58
	0x0075 - 0x007a (6)      goto 14

	match 19


state 51
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x006d (13)     goto 14
	0x006e                   goto 59
	0x006f - 0x007a (12)     goto 14

	match 19


state 52
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 14


state 53
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0073 (19)     goto 14
	0x0074                   goto 60
	0x0075 - 0x007a (6)      goto 14

	match 19


state 54
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 61
	0x0066 - 0x007a (21)     goto 14

	match 19


state 55
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 17


state 56
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 11


state 57
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 62
	0x0066 - 0x007a (21)     goto 14

	match 19


state 58
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 63
	0x0066 - 0x007a (21)     goto 14

	match 19


state 59
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 15


state 60
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 6


state 61
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0063 (3)      goto 14
	0x0064                   goto 64
	0x0065 - 0x007a (22)     goto 14

	match 19


state 62
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 12


state 63
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 18


state 64
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0074 (20)     goto 14
	0x0075                   goto 65
	0x0076 - 0x007a (5)      goto 14

	match 19


state 65
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0071 (17)     goto 14
	0x0072                   goto 66
	0x0073 - 0x007a (8)      goto 14

	match 19


state 66
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x0064 (4)      goto 14
	0x0065                   goto 67
	0x0066 - 0x007a (21)     goto 14

	match 19


state 67
	0x0030 - 0x0039 (10)     goto 14
	0x0061 - 0x007a (26)     goto 14

	match 8


#############################################################################
# Summary
#############################################################################

1 start state(s)
24 expression(s), 67 state(s)


#############################################################################
# End of File
#############################################################################
