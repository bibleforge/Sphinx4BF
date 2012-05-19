//
// $Id: sphinxstemen.cpp 3087 2012-01-30 23:07:35Z shodan $
//

//
// Copyright (c) 2001-2012, Andrew Aksyonoff
// Copyright (c) 2008-2012, Sphinx Technologies Inc
// All rights reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//

#include "sphinx.h" // for UNALIGNED_RAM_ACCESS

#if defined(_MSC_VER) && !defined(__cplusplus)
#define inline
#endif


struct strong_irregular
{
	BYTE form[12], add[8];
	int len;
};

static strong_irregular en_strong_irregular_a[] =
{
    { "abode",  "id",   2 },
    { "arose",  "is",   2 },
    { "arisen", "",     4 },
    { "ate",    "eat",  0 },
    { "awoke",  "ak",   2 },
    { "awaken", "",     4 }
};

static strong_irregular en_strong_irregular_b[] =
{
    { "befallen",   "",     5 }, // rare
    { "befell",     "al",   3 }, // rare
    { "beheld",     "old",  3 }, // rare
    { "besought",   "eech", 3 }, // rare
  //{ "bore",       "ear",  1 }, // Cause confusion with "bore" (as in to drill)
  //{ "born",       "ear",  1 }, // born and bear usually have different meanings
    { "became",     "om",   3 }, /// check
    { "began",      "in",   3 },
    { "begot",      "et",   3 }, // rare
    { "begotten",   "et",   3 }, // rare
    { "begun",      "in",   3 },
    { "bent",       "d",    3 },
    { "bidden",     "",     3 }, // archaic
    { "bade",       "id",   1 },
    { "bound",      "ind",  1 },
    { "bitten",     "e",    3 },
    { "bit",        "e",    3 },
    { "bits",       "e",    3 },
    { "blew",       "ow",   2 },
    { "blown",      "",     4 },
    { "bred",       "ed",   3 },
    { "breed",      "",     5 },
    { "brethren",   "other",2 }, // archaic
    { "brake",      "ok",   2 }, /// check
    { "broke",      "",     4 },
    { "broken",     "",     4 },
    { "brought",    "ing",  2 },
    { "broughtest", "ing",  2 }, // archaic
    { "brung",      "ing",  2 },
    { "built",      "d",    4 },
    { "burnt",      "",     4 }, // archaic
    { "bought",     "uy",   1 }
};

static strong_irregular en_strong_irregular_c[] =
{
    { "caught",     "tch",  2 },
    { "came",       "ome",  1 }, /// check (something is wrong (they came to Mahanaim) has no results)
  //{ "canning",    "",     7 },
  //{ "cannings",   "",     7 },
    { "canst",      "",     3 }, // archaic
    { "comely",     "i",    5 },
    { "could",      "an",   1 },
    { "couldest",   "an",   1 }, // archaic
    { "children",   "",     5 },
    { "chose",      "os",   3 }, /// check
    { "chosen",     "os",   3 }, /// check
  //{ "clung",      "ing",  2 }, // not used
    { "crept",      "ep",   3 }  // archaic
};

static strong_irregular en_strong_irregular_d[] =
{
  //{ "data",       "um",   3 }, // not used
    { "dealt",      "",     4 },
    { "did",        "o",    1 },
    { "didst",      "o",    1 }, // archaic
    { "done",       "",     2 },
    { "does",       "",     2 },
    { "doth",       "",     2 }, // archaic
    { "dost",       "",     2 }, // archaic
  //{ "dove",       "ive",  1 }, /// not used
    { "drawn",      "",     4 },
    { "drew",       "aw",   2 },
    { "driven",     "",     5 },
    { "drove",      "ive",  2 }, /// check
    { "drank",      "ink",  2 },
    { "drunk",      "ink",  2 },
    { "dug",        "ig",   1 },
    { "dwelling",   "",     8 }, ///NOTE: "dwelling" is primarily used as a noun
    { "dwellings",  "",     8 },
    { "dwelt",      "l",    4 },
    { "dieth",      "",     3 }, /// check
    { "diest",      "",     3 }, /// check
    { "dying",      "ie",   1 }  /// check
};

static strong_irregular en_strong_irregular_e[] =
{
  //{ "early",      "i",       4 }, // not used
    { "eaten",      "",        3 },
    { "enquire",    "inquir",  0 }, // rare
    { "enquired",   "inquir",  0 }, // rare
    { "enquiry",    "inquir",  0 }, // rare
    { "enquiring",  "inquir",  0 }, // rare
    { "exceed",     "",        6 }
};

static strong_irregular en_strong_irregular_f[] =
{
    { "fell",       "all",  1 },
    { "fallen",     "",     4 },
    { "fed",        "ed",   2 },
    { "feed",       "",     4 },
    { "feet",       "oot",  1 },
    { "felt",       "el",   2 },
    { "fought",     "ight", 1 },
    { "found",      "ind",  1 },
    { "fled",       "e",    3 }, /// check
    { "fleddest",   "e",    3 }, /// check
  //{ "fleddeth"    "e",    3 }, // extremely rare
    { "fleest",     "",     4 },
    { "fleeth",     "",     4 },
  //{ "flung",      "ing",  2 }, // not used
    { "flew",       "i",    2 }, ///NOTE: "fly" is stemmed as "fli".
    { "flies",      "",     5 }, ///NOTE: "files" always refers to the insect, not the verb.
    { "flown",      "i",    2 }, ///NOTE: "fly" is stemmed as "fli".
    { "forbad",     "id",   4 },
    { "forbade",    "id",   4 },
    { "forbidden",  "",     6 },
    { "foreknew",   "ow",   6 },
    { "foreknown",  "",     8 },
    { "foresaw",    "e",    5 }, ///NOTE: foresee is stemmed to "forese".
    { "foreseeing", "",     6 }, /// check
    { "foreseen",   "",     6 },
    { "foretold",   "el",   5 },
    { "forgot",     "et",   4 },
    { "forgotten",  "et",   4 },
    { "forgave",    "iv",   4 }, /// check
    { "forgavest",  "iv",   4 },
  //{ "forgaveth",  "iv",   4 }, // extremely rare
    { "forgiven",   "",     6 },
    { "forsaken",   "",     6 },
    { "forsook",    "ak",   4 },
    { "forsookest", "ak",   4 },
    { "froze",      "eez",  2 },
    { "frozen",     "eez",  2 }
};

static strong_irregular en_strong_irregular_g[] =
{
    { "gave",   "ive",  1 }, /// check
    { "gaveth", "ive",  1 },
  //{ "gavest", "ive",  1 }, // extremely rare
  //{ "geese",  "oos",  1 },
    { "gently", "",     5 },
    { "given",  "",     4 },
    { "goings", "",     6 },
    { "gone",   "",     2 },
    { "got",    "et",   1 },
    { "gotten", "et",   1 },
    { "graft",  "f",    4 },
    { "grew",   "own",  2 },
  //{ "ground", "ind",  2 }, This will cause problems with the noun form
    { "grown",  "",     5 }
};

static strong_irregular en_strong_irregular_h[] =
{
    { "had",         "ve",  2 }, /// check
    { "hadst",       "ve",  2 }, // archaic
  //{ "haddest",     "ve",  2 }, // extremely rare
    { "hast",        "ve",  2 }, // archaic
    { "has",         "ve",  2 },
  //{ "haste",       "",    5 }, // unnecessary in Present Day English
  //{ "hasted",      "",    5 }, // unnecessary in Present Day English
    { "hasten",      "",    4 }, // unnecessary in Present Day English(?) // archaic
    { "hastening",   "",    4 }, // archaic
    { "hastened",    "",    4 }, // archaic
    { "hasteneth",   "",    4 }, // archaic
    { "heard",       "",    4 },
    { "heardest",    "",    4 }, // archaic
    ///NOTE: The word "holds" is used in the Bible only as a noun, such as "strong holds"; however, it is a common Present Day English form.
    { "held",        "old", 1 },
    { "hewn",        "",    3 },
    { "hid",         "e",   3 }, /// check
    { "hidden",      "e",   3 },
  //{ "howe",        "",    4 }, // rare
    ///NOTE: "hanging" almost always refers to the noun; "hangings" always does.
    { "hung",        "ang", 1 }
};
/*
static strong_irregular en_strong_irregular_i[] =
{
    { "idly",       "", 3 },
    { "inning",     "", 6 },
    { "innings",    "", 6 }
};
*/
static strong_irregular en_strong_irregular_k[] =
{
    { "kept",   "ep",   2 },
    { "knelt",  "el",   3 },
    { "knew",   "ow",   2 },
    { "known",  "",     4 }
};

static strong_irregular en_strong_irregular_l[] =
{
    { "laid",   "y",    2 },
    { "laden",  "",     4 },
  //{ "lead",   "d",    2 }, // This will cause problems with the noun form
    { "lept",   "ap",   2 },
  //{ "learnt", "",     5 }, // rare
    { "left",   "av",   2 }, // Could cause problems with the adj form
    { "lent",   "d",    3 },
    { "lain",   "ie",   1 },
    { "lien",   "",     3 }, // archaic
    { "lit",    "ght",  2 },
  //{ "lost",   "e",    3 }, // conflics
    { "lying",  "ie",   1 }
};

static strong_irregular en_strong_irregular_m[] =
{
    { "made",       "ke",   2 }, /// check
    { "men",        "an",   1 },
    { "met",        "et",   2 },
    { "might",      "ay",   1 }, // Could cause false hits with the subjunctive use of "may"
  //{ "mistook",    "ake",  4 },
  //{ "mistaken",   "",     7 },
    { "mice",       "ous",  1 },
    { "mown",       "",     3 }
};
/*
static strong_irregular en_strong_irregular_n[] =
{
    { "news",   "", 4 }
};
*/
static strong_irregular en_strong_irregular_o[] =
{
    { "only",       "",     4 },
  //{ "outing",     "",     6 }, // not used
  //{ "outings",    "",     6 }, // not used
    { "overcame",   "om",   5 },
  //{ "overdid",    "o",    5 }, /// not used
  //{ "overdone",   "",     6 }, /// not used
    { "overtook",   "ak",   5 }, /// check
    { "overtaken",  "",     8 },
    { "overthrew",  "ow",   7 },
    { "overthrown", "",     9 },
    { "oxen",       "",     2 }
};

static strong_irregular en_strong_irregular_p[] =
{
    { "paid",       "y",    2 },
  //{ "people",     "rson", 2 }, // Causes problems with "peoples"
    { "pled",       "ad",   3 },
    { "pluckt",     "",     5 }, // rare
    { "proceed",    "",     7 }
  //{ "proven",     "",     5 }
};

static strong_irregular en_strong_irregular_r[] =
{
  //{ "rebuilt",    "d",    6 }, //?
    { "rent",       "d",    3 }, // false hits with the noun rent
    { "repaid",     "y",    4 },
  //{ "rewrote",    "ite",  4 },
  //{ "rewritten",   "e",   6 },
    { "rode",       "ide",  1 }, /// check
    { "ridden",     "e",    3 }, /// check
    { "rang",       "ing",  1 },
    { "rung",       "ing",  1 },
    { "risen",      "",     4 },
    { "rose",       "ise",  1 }, /// check
    { "ran",        "un",   1 }
};

static strong_irregular en_strong_irregular_s[] =
{
    { "said",       "y",        2 },
    { "sang",       "ing",      1 },
    { "sank",       "ink",      1 },
    { "sat",        "it",       1 },
    { "saw",        "ee",       1 },
  //{ "sawn",       "",         3 }, // could cause conflicts
    { "seed",       "",         4 },
    { "seen",       "",         3 },
    { "sent",       "d",        3 },
    { "sewn",       "",         3 },
    { "shaken",     "",         5 },
    { "shalt",      "l",        4 },
    { "shaven",     "",         5 },
    { "shook",      "ake",      2 }, /// check
    { "shone",      "ine",      2 },
    { "shorn",      "ear",      2 },
    { "shot",       "ot",       3 },
    { "show",       "ew",       2 }, // archaic
  //{ "shown",      "ew",       2 }, // archaic // not used
  //{ "shewn",      "",         4 }, // archaic // not used
    { "showed",     "ew",       2 }, // archaic
    { "showbread",  "ewbread",  2 }, // rare
    { "shrank",     "ink",      3 }, //used?
    { "shrunk",     "ink",      3 }, //used?
    { "singly",     "",         5 },
    { "skies",      "y",        2 },
    { "sky",        "",         3 },
    { "slang",      "ing",      2 },
    { "slept",      "ep",       3 },
    { "slain",      "y",        3 },
    { "slew",       "ay",       2 },
    { "slide",      "",         4 },    /// check
    { "slidden",    "",         4 }, //needed? backslidden?
    { "slung",      "ing",      2 }, //used?
    { "smitten",    "e",        4 }, // rare /// check
    { "smote",      "ite",      2 },
  //{ "snuck",      "eak",      2 },
    { "sold",       "ell",      1 },
    { "sought",     "eek",      1 },
    { "sown",       "",         3 },
    { "spake",      "eak",      2 },
    { "spoke",      "eak",      2 },
    { "spoken",     "eak",      2 },
    { "sped",       "ed",       3 },
    { "spent",      "d",        4 },
    { "spilt",      "l",        4 },
    { "span",       "in",       2 },
    { "spun",       "in",       2 },
    { "spat",       "it",       2 },
    { "sprang",     "ing",      3 },
    { "sprung",     "ing",      3 },
    { "stood",      "and",      2 },
    { "stole",      "eal",      2 },
    { "stolen",     "eal",      2 },
    { "stuck",      "ick",      2 }, // could cause problems
    { "stung",      "ing",      2 },
    { "stank",      "ink",      2 },
    { "stunk",      "ink",      2 },
    { "struck",     "ike",      3 },
  //{ "strang",     "ing",      3 },
  //{ "strung",     "ing",      3 },
    { "striven",    "",         6 }, // rare
    { "strove",     "ive",      3 }, /// check
    { "succeed",    "",         7 }, // necessary?
    { "sung",       "ing",      1 },
    { "sunk",       "ink",      1 },
    { "swam",       "im",       2 },
  //{ "swang",      "ing",      2 },
    { "swept",      "ep",       3 },
    { "swore",      "ear",      2 },
    { "sworn",      "ear",      2 },
    { "swollen",    "ell",      2 },
    { "swum",       "im",       2 }
  //{ "swung",      "ing",      2 }
};

static strong_irregular en_strong_irregular_t[] =
{
    { "taken",      "",     4 },
    { "taught",     "each", 1 },
    { "teeth",      "ooth", 1 },
    { "took",       "ake",  1 },
    { "tore",       "ear",  1 },
    { "torn",       "ear",  1 },
    { "told",       "ell",  1 },
    { "thought",    "ink",  2 },
  //{ "thriven",    "",     6 }, // rare
    { "threw",      "ow",   3 },
    { "thrown",     "",     5 },
    { "trod",       "ead",  2 },
    { "trodden",    "ead",  2 }, // archaic
    { "tying",      "ie",   1 } /// check
};

static strong_irregular en_strong_irregular_u[] =
{
  //{ "ugly",       "i",    3 },
    { "understood", "and",  7 },
    { "upheld",     "old",  3 }
};

static strong_irregular en_strong_irregular_w[] =
{
    { "waxen",      "",         3 }, // archaic
    { "went",       "go",       0 },
    { "whom",       "",         3 },
    { "whomsoever", "soev",     3 }, // rare
    { "wilt",       "l",        3 },
    { "woke",       "ake",      1 },
    { "woken",      "ake",      1 },
    { "women",      "an",       3 },
    { "wore",       "ear",      1 },
    { "worn",       "ear",      1 },
    { "wove",       "eav",      1 },
    { "woven",      "eav",      1 },
  //{ "wound",      "ind",      1 }, // could cause conflicts
    { "won",        "in",       1 },
    { "withdrawn",   "",        8 },
    { "withdrew",   "aw",       6 },
    { "withheld",   "old",      5 },
    { "withholden", "",         8 },
    { "withstood",  "and",      6 },
    { "wrung",      "ing",      2 },
    { "written",    "e",        4 },
    { "wrought",    "ork",      1 },
    { "wrote",      "ite",      2 }
};

// Other possible words:
// shall should will would
//  { "is",   "be", 0 },
//  { "am",   "be", 0 },
//  { "are",  "be", 0 },
//  { "was",  "be", 0 },
//  { "were", "be", 0 },
// he him his
// it its it's
// she her hers
// they them
// thou thy thine


// #define SNOWBALL2011

static unsigned char stem_en_doubles[] = "bdfgmnprt";

static unsigned char vowel_map[] =
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 0
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 1
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 2
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 3
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 4
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 5
	//` a b c d e f g h i j k l m n o - NOLINT
	"\0\1\0\0\0\1\0\0\0\1\0\0\0\0\0\1" // 6
	//p q r s t u v w x y z - NOLINT
	"\0\0\0\0\0\1\0\0\0\1\0\0\0\0\0\0" // 7
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 8
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // 9
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // a
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // b
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // c
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // d
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" // e
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"; // f

#define is_vowel(idx) vowel_map[word[idx]]

static inline int stem_en_id ( unsigned char l )
{
	register unsigned char * v = stem_en_doubles;
	while ( *v && *v!=l ) v++;
	return ( *v==l ) ? 1 : 0;
}

static inline int stem_en_ivwxy ( unsigned char l )
{
	return vowel_map[l] || l=='w' || l=='x' || l=='Y';
}

void stem_en_init ()
{
}

bool stem_en_strong_irregular (BYTE *word, struct strong_irregular *stem_en_strong_irregular_letter, int size)
{
	int i;
	for (i = 0; i < (int)(size / sizeof(strong_irregular)); i++) {
		if (strcmp((char*)word, (char*)stem_en_strong_irregular_letter[i].form) == 0) {
			//strcpy((char*)word, (char*)stem_en_strong_irregular_letter[i].add);
			//word += stem_en_strong_irregular_letter[i].len;
			word[stem_en_strong_irregular_letter[i].len] = '\0';
			strcat((char*)word, (char*)stem_en_strong_irregular_letter[i].add);
			/// Testing the results.
			//fprintf ( stdout, "\nStrong stem\n");
			//fprintf ( stdout, (char*)word );
			return true;
		}
	}
	return false;
}

#define EXCBASE(b) ( iword==( ( (int)b[3]<<24 ) + ( (int)b[2]<<16 ) + ( (int)b[1]<<8 ) + (int)b[0] ) )
#define EXC4(a,b) ( len==4 && EXCBASE(b) )
#define EXC5(a,b) ( len==5 && EXCBASE(b) )
#define EXC6(a,b) ( len==6 && EXCBASE(b) && a[4]==b[4] )
#define EXC7(a,b) ( len==7 && EXCBASE(b) && a[4]==b[4] && a[5]==b[5] )
#define EXC8(a,b) ( len==8 && EXCBASE(b) && a[4]==b[4] && a[5]==b[5] && a[6]==b[6] )

void stem_en ( unsigned char * word, int len )
{
	int i, first_vowel, r1, r2, iword;
	unsigned char has_Y = 0;

	if (len <= 2) {
		// Convert "ye" to "you."
		if (strcmp((char*)word, "ye") == 0) strcpy((char*)word, "you");
		return;
	}

	// Check for strong verbs and irregular words.
	switch (int(word[0])) {
		case  97:if (stem_en_strong_irregular(word, en_strong_irregular_a, sizeof(en_strong_irregular_a))) { return; } break;
		case  98:if (stem_en_strong_irregular(word, en_strong_irregular_b, sizeof(en_strong_irregular_b))) { return; } break;
		case  99:if (stem_en_strong_irregular(word, en_strong_irregular_c, sizeof(en_strong_irregular_c))) { return; } break;
		case 100:if (stem_en_strong_irregular(word, en_strong_irregular_d, sizeof(en_strong_irregular_d))) { return; } break;
		case 101:if (stem_en_strong_irregular(word, en_strong_irregular_e, sizeof(en_strong_irregular_e))) { return; } break;
		case 102:if (stem_en_strong_irregular(word, en_strong_irregular_f, sizeof(en_strong_irregular_f))) { return; } break;
		case 103:if (stem_en_strong_irregular(word, en_strong_irregular_g, sizeof(en_strong_irregular_g))) { return; } break;
		case 104:if (stem_en_strong_irregular(word, en_strong_irregular_h, sizeof(en_strong_irregular_h))) { return; } break;
//		case 105:if (stem_en_strong_irregular(word, en_strong_irregular_i, sizeof(en_strong_irregular_i))) { return; } break;
		case 107:if (stem_en_strong_irregular(word, en_strong_irregular_k, sizeof(en_strong_irregular_k))) { return; } break;
		case 108:if (stem_en_strong_irregular(word, en_strong_irregular_l, sizeof(en_strong_irregular_l))) { return; } break;
		case 109:if (stem_en_strong_irregular(word, en_strong_irregular_m, sizeof(en_strong_irregular_m))) { return; } break;
//		case 110:if (stem_en_strong_irregular(word, en_strong_irregular_n, sizeof(en_strong_irregular_n))) { return; } break;
		case 111:if (stem_en_strong_irregular(word, en_strong_irregular_o, sizeof(en_strong_irregular_o))) { return; } break;
		case 112:if (stem_en_strong_irregular(word, en_strong_irregular_p, sizeof(en_strong_irregular_p))) { return; } break;
		case 114:if (stem_en_strong_irregular(word, en_strong_irregular_r, sizeof(en_strong_irregular_r))) { return; } break;
		case 115:if (stem_en_strong_irregular(word, en_strong_irregular_s, sizeof(en_strong_irregular_s))) { return; } break;
		case 116:if (stem_en_strong_irregular(word, en_strong_irregular_t, sizeof(en_strong_irregular_t))) { return; } break;
		case 117:if (stem_en_strong_irregular(word, en_strong_irregular_u, sizeof(en_strong_irregular_u))) { return; } break;
		case 119:if (stem_en_strong_irregular(word, en_strong_irregular_w, sizeof(en_strong_irregular_w))) { return; } break;
	}
	
#if UNALIGNED_RAM_ACCESS
	iword = *(int*)word;
#else
	iword = ( (int)word[3]<<24 ) + ( (int)word[2]<<16 ) + ( (int)word[1]<<8 ) + (int)word[0];
#endif

	// check for 3-letter exceptions (currently just one, "sky") and shortcuts
	if ( len==3 )
	{
#define CHECK3(c1,c2,c3) if ( iword==( (c1<<0)+(c2<<8)+(c3<<16) ) ) return;
#ifdef SNOWBALL2011
#define CHECK3A CHECK3
#else
#define CHECK3A(c1,c2,c3) if ( iword==( (c1<<0)+(c2<<8)+(c3<<16) ) ) { word[2] = '\0'; return; }
#endif
		CHECK3 ( 't', 'h', 'e' );
		CHECK3 ( 'a', 'n', 'd' );
		CHECK3 ( 'y', 'o', 'u' );
		CHECK3A ( 'w', 'a', 's' );
		CHECK3A ( 'h', 'i', 's' );
		CHECK3 ( 'f', 'o', 'r' );
		CHECK3 ( 'h', 'e', 'r' );
		CHECK3 ( 's', 'h', 'e' );
		CHECK3 ( 'b', 'u', 't' );
		CHECK3 ( 'h', 'a', 'd' );
		CHECK3 ( 's', 'k', 'y' );
	}

	// check for 4..8-letter exceptions
	if ( len>=4 && len<=8 )
	{
		// check for 4-letter exceptions and shortcuts
		if ( len==4 )
		{
			// shortcuts
			if ( iword==0x74616874 ) return; // that
			if ( iword==0x68746977 ) return; // with
			if ( iword==0x64696173 ) return; // said
			if ( iword==0x6d6f7266 ) return; // from

			// exceptions
			if ( iword==0x7377656e ) return; // news
			if ( iword==0x65776f68 ) return; // howe
		}
/*
		// all those exceptions only have a few valid endings; early check
		switch ( word[len-1] )
		{
			case 'd':
				if ( EXC7 ( word, "proceed" ) )		return;
				if ( EXC6 ( word, "exceed" ) )		return;
				if ( EXC7 ( word, "succeed" ) )		return;
				break;

			case 'g':
				if ( EXC5 ( word, "dying" ) )		{ word[1] = 'i'; word[2] = 'e'; word[3] = '\0'; return; }
				if ( EXC5 ( word, "lying" ) )		{ word[1] = 'i'; word[2] = 'e'; word[3] = '\0'; return; }
				if ( EXC5 ( word, "tying" ) )		{ word[1] = 'i'; word[2] = 'e'; word[3] = '\0'; return; }
				if ( EXC6 ( word, "inning" ) )		return;
				if ( EXC6 ( word, "outing" ) )		return;
				if ( EXC7 ( word, "canning" ) )		return;
#ifdef SNOWBALL2011
				if ( EXC7 ( word, "herring" ) )		return;
				if ( EXC7 ( word, "earring" ) )		return;
#endif
				break;

			case 's':
				if ( EXC5 ( word, "skies" ) )		{ word[2] = 'y'; word[3] = '\0'; return; }
				if ( EXC7 ( word, "innings" ) )		{ word[6] = '\0'; return; }
				if ( EXC7 ( word, "outings" ) )		{ word[6] = '\0';return; }
				if ( EXC8 ( word, "cannings" ) )	{ word[7] = '\0';return; }
#ifdef SNOWBALL2011
				if ( EXC4 ( word, "skis" ) )		{ word[3] = '\0'; return; }
				if ( EXC5 ( word, "atlas" ) )		return;
				if ( EXC6 ( word, "cosmos" ) )		return;
				if ( EXC4 ( word, "bias" ) )		return;
				if ( EXC5 ( word, "andes" ) )		return;
				if ( EXC8 ( word, "herrings" ) )	{ word[7] = '\0'; return; }
				if ( EXC8 ( word, "earrings" ) )	{ word[7] = '\0'; return; }
				if ( EXC8 ( word, "proceeds" ) )	{ word[7] = '\0'; return; }
				if ( EXC7 ( word, "exceeds" ) )		{ word[6] = '\0'; return; }
				if ( EXC8 ( word, "succeeds" ) )	{ word[7] = '\0'; return; }
#endif
				break;

			case 'y':
				if ( EXC4 ( word, "idly" ) )		{ word[3] = '\0';return; }
				if ( EXC6 ( word, "gently" ) )		{ word[5] = '\0';return; }
				if ( EXC4 ( word, "ugly" ) )		{ word[3] = 'i'; word[4] = '\0'; return; }
				if ( EXC5 ( word, "early" ) )		{ word[4] = 'i'; word[5] = '\0'; return; }
				if ( EXC4 ( word, "only" ) )		{ word[3] = 'i'; word[4] = '\0'; return; }
				if ( EXC6 ( word, "singly" ) )		{ word[5] = '\0'; return; }
				break;
		}
	}
*/
	// hide consonant-style y's
	if ( word[0]=='y' )
		word[0] = has_Y = 'Y';
	for ( i=1; i<len; i++ )
		if ( word[i]=='y' && is_vowel ( i-1 ) )
			word[i] = has_Y = 'Y';

	// mark regions
	// R1 begins after first "vowel, consonant" sequence in the word
	// R2 begins after second "vowel, consonant" sequence
	if ( len>=5 && EXCBASE("gene") && word[4]=='r' )
	{
		r1 = 5; // gener-
		first_vowel = 1;
	}
#ifdef SNOWBALL2011
	else if ( len>=6 && EXCBASE("comm") && word[4]=='u' && word[5]=='n' )
	{
		r1 = 6; // commun-
		first_vowel = 1;
	} else if ( len>=5 && EXCBASE("arse") && word[4]=='n' )
	{
		r1 = 5; // arsen-
		first_vowel = 0;
	}
#endif
	else
	{
		for ( i=0; i<len && !is_vowel(i); i++ );
		first_vowel = i;

		for ( i=first_vowel; i<len-2; i++ )
			if ( is_vowel(i) && !is_vowel(i+1) )
				break;
		r1 = i+2;
	}
	for ( i=r1; i<len-2; i++ )
		if ( is_vowel(i) && !is_vowel(i+1) )
			break;
	r2 = i+2;

#define W(p,c) ( word[len-p]==c )

#define SUFF2(c2,c1) ( len>=2 && W(1,c1) && W(2,c2) )
#define SUFF3(c3,c2,c1) ( len>=3 && W(1,c1) && W(2,c2) && W(3,c3) )
#define SUFF4(c4,c3,c2,c1) ( len>=4 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) )
#define SUFF5(c5,c4,c3,c2,c1) ( len>=5 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) )
#define SUFF6(c6,c5,c4,c3,c2,c1) ( len>=6 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) && W(6,c6) )
#define SUFF7(c7,c6,c5,c4,c3,c2,c1) ( len>=7 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) && W(6,c6) && W(7,c7) )

#define SUFF3A(c3,c2) ( len>=3 && W(2,c2) && W(3,c3) )
#define SUFF4A(c4,c3,c2) ( len>=4 && W(2,c2) && W(3,c3) && W(4,c4) )
#define SUFF5A(c5,c4,c3,c2) ( len>=5 && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) )
#define SUFF6A(c6,c5,c4,c3,c2) ( len>=6 && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) && W(6,c6) )
#define SUFF7A(c7,c6,c5,c4,c3,c2) ( len>=6 && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) && W(6,c6) && W(7,c7) )

	///////////
	// STEP 1A 
	///////////

#ifdef SNOWBALL2011
#define IED_ACTION { if ( len-->4 ) len--; }
#else
#define IED_ACTION { if ( len--!=4 ) len--; }
#endif

	switch ( word[len-1] )
	{
		case 'd':
			if ( word[len-3]=='i' && word[len-2]=='e' )
				IED_ACTION
			break;
		case 's':
			if ( SUFF4 ( 's', 's', 'e', 's' ) ) // faster that suff4a for some reason!
				len -= 2;
			else if ( word[len-3]=='i' && word[len-2]=='e' )
				IED_ACTION
			else if ( word[len-2]!='u' && word[len-2]!='s' )
			{
#ifdef SNOWBALL2011
				if ( first_vowel<=len-3 )
#endif

				len--;
			}
			break;
	}

	///////////
	// STEP 1B
	///////////

	i = 0;
	switch ( word[len-1] )
	{
		case 'd':
			if ( SUFF3A ( 'e', 'e' ) )				{ if ( len-3>=r1 ) len--; break; }
			if ( word[len-2]=='e' )					i = 2;
			break;

		case 'y':
			if ( word[len-2]=='l' )
			{
				if ( SUFF5A ( 'e', 'e', 'd', 'l' ) )	{ if ( len-5>=r1 ) len -= 3; break; }
				if ( SUFF4A ( 'e', 'd', 'l' ) )			{ i = 4; break; }
				if ( SUFF5A ( 'i', 'n', 'g', 'l' ) )	{ i = 5; break; }
			}
			break;

		case 'g':
			if ( SUFF3A ( 'i', 'n' ) )				i = 3;
			break;
        
        // Special endings for Early Modern English
		case 't':
			if ( SUFF3A ( 'e', 's' ) )				{ i = 3; break; }
			if ( SUFF4A ( 'e', 'd', 's' ) )			{ i = 4; break; }
		case 'h':
			if ( SUFF3A ( 'e', 't' ) )				i = 3;
			break;
	}

	if ( i && first_vowel<len-i )
	{
		len -= i;
		if ( SUFF2 ( 'a', 't' ) || SUFF2 ( 'b', 'l' ) || SUFF2 ( 'i', 'z' ) )
			word[len++] = 'e';
		else if ( len>=2 && word[len-1]==word[len-2] && stem_en_id ( word[len-1] ) )
			len--;
		else if ( ( len==2 && is_vowel(0) && !is_vowel(1) )
			|| ( len==r1 && !is_vowel ( len-3 ) && is_vowel ( len-2 ) && !stem_en_ivwxy ( word[len-1] ) ) )
		{
			word[len++] = 'e';
		}
	}

	///////////
	// STEP 1C
	///////////

	if ( len>2
		&& ( word[len-1]=='y' || word[len-1]=='Y' )
		&& !is_vowel ( len-2 ) )
	{
		word[len-1] = 'i';
	}

	//////////
	// STEP 2
	//////////

	if ( len-2>=r1 )
		switch ( word[len-1] )
	{
		case 'i':
			if ( len>=3 && ( W ( 2, 'c' ) || W ( 2, 'l' ) || W ( 2, 't' ) ) )
			{
				if ( SUFF4A ( 'e', 'n', 'c' ) )				{ if ( len-4>=r1 ) word[len-1] = 'e'; break; }
				if ( SUFF4A ( 'a', 'n', 'c' ) )				{ if ( len-4>=r1 ) word[len-1] = 'e'; break; }
				if ( SUFF4A ( 'a', 'b', 'l' ) )				{ if ( len-4>=r1 ) word[len-1] = 'e'; break; }
				if ( SUFF3A ( 'b', 'l' ) )					{ if ( len-3>=r1 ) word[len-1] = 'e'; break; }

				if ( SUFF5A ( 'e', 'n', 't', 'l' ) )		{ if ( len-5>=r1 ) len -= 2; break; }
				if ( SUFF5A ( 'a', 'l', 'i', 't' ) )		{ if ( len-5>=r1 ) len -= 3; break; }
				if ( SUFF5A ( 'o', 'u', 's', 'l' ) )		{ if ( len-5>=r1 ) len -= 2; break; }

				if ( SUFF5A ( 'i', 'v', 'i', 't' ) )		{ if ( len-5>=r1 ) { word[len-3] = 'e'; len -= 2; } break; }
				if ( SUFF6A ( 'b', 'i', 'l', 'i', 't' ) )	{ if ( len-6>=r1 ) { word[len-5] = 'l'; word[len-4] = 'e'; len -= 3; } break; }
				if ( SUFF5A ( 'f', 'u', 'l', 'l' ) )		{ if ( len-5>=r1 ) len -= 2; break; }
				if ( SUFF6A ( 'l', 'e', 's', 's', 'l' ) )	{ if ( len-6>=r1 ) len -= 2; break; }
			}

#ifdef SNOWBALL2011
			if ( len-3>=r1 && SUFF3A ( 'o', 'g' ) && word[len-4]=='l' ) { len -= 1; break; }
#else
			if ( len-3>=r1 && SUFF3A ( 'o', 'g' ) ) { len -= 1; break; }
#endif

			if ( len-2>=r1 && word[len-2]=='l' )
				len -= 2;
			else
				break;

			if ( len-2>=r1 && SUFF2 ( 'a', 'l' ) )
			{
				len -= 2;
				if ( len-5>=r1 && SUFF5 ( 'a', 't', 'i', 'o', 'n' ) )
				{
					len -= 3;
					word[len++] = 'e';
					break;
				}
				if ( SUFF4 ( 't', 'i', 'o', 'n' ) )
					break;
				len += 2;
			} else
			{
				switch ( word[len-1] )
				{
					case 'b':
					case 'c':
					case 'd':
					case 'e':
					case 'g':
					case 'h':
					case 'k':
					case 'm':
					case 'n':
					case 'r':
					case 't':
						break;
					default:
						len += 2;
						break;
				}
			}
			break;

		case 'l':
			if ( SUFF7A ( 'a', 't', 'i', 'o', 'n', 'a' ) )	{ if ( len-7>=r1 ) { word[len-5] = 'e'; len -= 4; } break; }
			if ( SUFF6A ( 't', 'i', 'o', 'n', 'a' ) )		{ if ( len-6>=r1 ) len -= 2; break; }
			break;

		case 'm':
			if ( SUFF5A ( 'a', 'l', 'i', 's' ) )			{ if ( len-5>=r1 ) len -= 3; break; }
			break;

		case 'n':
			if ( SUFF7A ( 'i', 'z', 'a', 't', 'i', 'o' ) )	{ if ( len-7>=r1 ) { word[len-5] = 'e'; len -= 4; } break; }
			if ( SUFF5A ( 'a', 't', 'i', 'o' ) )			{ if ( len-5>=r1 ) { word[len-3] = 'e'; len -= 2; } break; }
			break;

		case 'r':
			if ( SUFF4A ( 'i', 'z', 'e' ) )	{ if ( len-4>=r1 ) len -= 1; break; }
			if ( SUFF4A ( 'a', 't', 'o' ) )	{ if ( len-4>=r1 ) { word[len-2] = 'e'; len -= 1; } break; }
			break;

		case 's':
			if ( len-7>=r1 && (
				SUFF7A ( 'f', 'u', 'l', 'n', 'e', 's' ) ||
				SUFF7A ( 'o', 'u', 's', 'n', 'e', 's' ) ||
				SUFF7A ( 'i', 'v', 'e', 'n', 'e', 's' ) ) )
			{
				len -= 4;
			}
			break;
	}

	//////////
	// STEP 3
	//////////

	if ( len-3>=r1 )
		switch ( word[len-1] )
	{
		case 'e':
			if ( SUFF5A ( 'a', 'l', 'i', 'z' ) )	{ if ( len-5>=r1 ) len -= 3; break; }
			if ( SUFF5A ( 'i', 'c', 'a', 't' ) )	{ if ( len-5>=r1 ) len -= 3; break; }
#ifdef SNOWBALL2011
			if ( SUFF5A ( 'a', 't', 'i', 'v' ) )	{ if ( len-5>=r2 ) len -= 5; break; }
#else
			if ( SUFF5A ( 'a', 't', 'i', 'v' ) )	{ if ( len-5>=r1 ) len -= 5; break; }
#endif
			break;

		case 'i':
			if ( SUFF5A ( 'i', 'c', 'i', 't' ) )	{ if ( len-5>=r1 ) len -= 3; break; }
			break;

		case 'l':
			if ( SUFF4A ( 'i', 'c', 'a' ) )			{ if ( len-4>=r1 ) len -= 2; break; }
			if ( SUFF3A ( 'f', 'u' ) )				{ len -= 3; break; }
			break;

		case 's':
			if ( SUFF4A ( 'n', 'e', 's' ) )			{ if ( len-4>=r1 ) len -= 4; break; }
			break;
	}

	//////////
	// STEP 4
	//////////

	if ( len-2>=r2 )
		switch ( word[len-1] )
	{
		case 'c':
			if ( word[len-2]=='i' ) len -= 2; // -ic
			break;

		case 'e':
			if ( len-3>=r2 )
			{
				if ( SUFF4A ( 'a', 'n', 'c' ) )		{ if ( len-4>=r2 ) len -= 4; break; }
				if ( SUFF4A ( 'e', 'n', 'c' ) )		{ if ( len-4>=r2 ) len -= 4; break; }
				if ( SUFF4A ( 'a', 'b', 'l' ) )		{ if ( len-4>=r2 ) len -= 4; break; }
				if ( SUFF4A ( 'i', 'b', 'l' ) )		{ if ( len-4>=r2 ) len -= 4; break; }
				if ( SUFF3A ( 'a', 't' ) )			{ len -= 3; break; }
				if ( SUFF3A ( 'i', 'v' ) )			{ len -= 3; break; }
				if ( SUFF3A ( 'i', 'z' ) )			{ len -= 3; break; }
			}
			break;

		case 'i':
			if ( SUFF3A ( 'i', 't' ) )				{ if ( len-3>=r2 ) len -= 3; break; }
			break;

		case 'l':
			if ( word[len-2]=='a' ) len -= 2; // -al
			break;

		case 'm':
			if ( SUFF3A ( 'i', 's' ) )				{ if ( len-3>=r2 ) len -= 3; break; }
			break;

		case 'n':
			if ( len-3>=r2 && SUFF3 ( 'i', 'o', 'n' ) && ( word[len-4]=='t' || word[len-4]=='s' ) )
				len -= 3;
			break;

		case 'r':
			if ( word[len-2]=='e' ) len -= 2; // -er
			break;

		case 's':
			if ( SUFF3A ( 'o', 'u' ) )				{ if ( len-3>=r2 ) len -= 3; break; }
			break;

		case 't':
			if ( word[len-2]=='n' )
			{
				if ( SUFF5A ( 'e', 'm', 'e', 'n' ) )	{ if ( len-5>=r2 ) len -= 5; break; }
				if ( SUFF4A ( 'm', 'e', 'n' ) )			{ if ( len-4>=r2 ) len -= 4; break; }
				if ( SUFF3A ( 'a', 'n' ) )				{ if ( len-3>=r2 ) len -= 3; break; }
				if ( SUFF3A ( 'e', 'n' ) )				{ if ( len-3>=r2 ) len -= 3; break; }
			}
			break;
	}

	//////////
	// STEP 5
	//////////

#ifdef SNOWBALL2011
	if ( len>r2 && word[len-1]=='l' && word[len-2]=='l' )
		len--;
	else
#endif
	while ( word[len-1]=='e' )
	{
		if ( len>r2 )
		{
			len--;
			break;
		}
		if ( len<=r1 )
			break;
		if ( len>3 && !is_vowel ( len-4 ) && is_vowel ( len-3 ) && !stem_en_ivwxy ( word[len-2] ) )
			break;
		if ( len==3 && is_vowel(0) && !is_vowel(1) )
			break;
		len--;
		break;
	}
#ifndef SNOWBALL2011
	if ( len>r2 && word[len-1]=='l' && word[len-2]=='l' )
		len--;
#endif

	////////////
	// FINALIZE
	////////////

	word[len] = 0;
	if ( has_Y )
		for ( i=0; i<len; i++ )
			if ( word[i]=='Y' )
				word[i] = 'y';
}

//
// $Id: sphinxstemen.cpp 3087 2012-01-30 23:07:35Z shodan $
//
