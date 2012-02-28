//
// $Id: sphinxstemen.cpp 1709 2009-02-27 10:30:10Z klirichek $
//

//
// Copyright (c) 2001-2008, Andrew Aksyonoff. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License. You should have
// received a copy of the GPL license along with this program; if you
// did not, you can find it at http://www.gnu.org/
//

#include "sphinx.h"
#include <string.h>

struct stem_table
{
	int len, nremove, nadd;
	BYTE suffix[10], add[3];
};

static stem_table en_step2[] =
{
	{ 4, 1, 1, "enci",	"e-" },
	{ 4, 1, 1, "anci",	"e-" },
	{ 4, 1, 1, "abli",	"e-" },
	{ 3, 1, 1, "bli",	"e-" },
	{ 5, 2, 0, "entli",	"--" },
	{ 5, 3, 0, "aliti",	"--" },
	{ 5, 2, 0, "ousli",	"--" },
	{ 5, 3, 1, "iviti",	"e-" },
	{ 6, 5, 2, "biliti",	"le" },
	{ 5, 2, 0, "fulli",	"--" },
	{ 6, 2, 0, "lessli",	"--" },

	{ 7, 5, 1, "ational",	"e-" },
	{ 6, 2, 0, "tional",	"--" },

	{ 5, 3, 0, "alism",	"--" },

	{ 7, 5, 1, "ization",	"e-" },
	{ 5, 3, 1, "ation",	"e-" },

	{ 4, 1, 0, "izer",	"--" },
	{ 4, 2, 1, "ator",	"e-" },

	{ 7, 4, 0, "fulness",	"--" },
	{ 7, 4, 0, "ousness",	"--" },
	{ 7, 4, 0, "iveness",	"--" }
};

static stem_table en_step3[] =
{
	{ 5, 3, 0, "alize",	"--" },
	{ 5, 3, 0, "icate",	"--" },
	{ 5, 5, 0, "ative",	"--" },

	{ 5, 3, 0, "iciti",	"--" },

	{ 4, 2, 0, "ical",	"--" },
	{ 3, 3, 0, "ful",	"--" },

	{ 4, 4, 0, "ness",	"--" },
	{ 4, 4, 0, "self",	"--" },
};

static stem_table en_step4[] =
{
	{ 2, 2, 0, "ic",	"--" },
	{ 4, 4, 0, "ance",	"--" },
	{ 4, 4, 0, "ence",	"--" },
	{ 4, 4, 0, "able",	"--" },
	{ 4, 4, 0, "ible",	"--" },
	{ 3, 3, 0, "ate",	"--" },
	{ 3, 3, 0, "ive",	"--" },
	{ 3, 3, 0, "ize ",	"--" },
	{ 3, 3, 0, "iti",	"--" },
	{ 2, 2, 0, "al",	"--" },
	{ 3, 3, 0, "ism",	"--" },
	{ 2, 2, 0, "er",	"--" },
	{ 3, 3, 0, "ous",	"--" },
	{ 5, 5, 0, "ement",	"--" },
	{ 4, 4, 0, "ment",	"--" },
	{ 3, 3, 0, "ant",	"--" },
	{ 3, 3, 0, "ent",	"--" }
};


struct strong_irregular
{
	BYTE form[11], add[8];
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
    { "buildedst",  "",     5 },
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
    { "fleddest"    "e",    3 }, /// check
  //{ "fleddeth"    "e",    3 }, // extremely rare
    { "fleest"      "",     4 },
    { "fleeth"      "",     4 },
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
    { "hearkenedst", "",    7 }, // archaic
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
    { "only",       "i",    3 },
    { "outing",     "",     6 },
    { "outings",    "",     6 },
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
    { "rid",        "e",    3 }, /// check
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
    { "shod",       "e",        3 }, // helpful?
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
    { "slept",      "ep",       3 },
    { "slain",      "y",        3 },
    { "slew",       "ay",       2 },
    { "slide",      "",         4 },    /// check
    { "slidden",    "",         4 },// needed? backslidden?
    { "slung",      "ing",      2 }, //used?
    { "smitten",    "",         4 }, // rare /// check
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
    { "split",      "ill",      2 },
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
    { "stridden",   "e",        5 },
    { "strod",      "id",       3 },
    { "struck",     "ik",       3 },
  //{ "strang",     "ing",      3 },
  //{ "strung",     "ing",      3 },
    { "striven",    "",         6 }, // rare
    { "strove",     "ive",      3 }, /// check
    { "succeed",    "",         7 },
    { "sung",       "ing",      1 },
    { "sunk",       "ink",      1 },
    { "swam",       "im",       2 },
  //{ "swang",      "ing",      2 },
    { "swept",      "ep",       3 },
    { "swore",      "ear",      2 },
    { "sworen",     "ear",      2 },
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
    { "tying",      "tie",  1 } /// check
};

static strong_irregular en_strong_irregular_u[] =
{
    { "ugly",       "i",    3 },
    { "understood", "and",  7 },
    { "upheld",     "old",  3 }
};

static strong_irregular en_strong_irregular_w[] =
{
    { "waxen",      "",         3 }, // archaic
    { "went",       "go",       0 },
    { "whom",       "",         3 },
    { "whomsoever", "soever",   3 }, // rare
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

static BYTE stem_en_vowels[] = "aeiouy";
static BYTE stem_en_vwxy[] = "aeiouywxY";
static BYTE stem_en_doubles[] = "bdfgmnprt";
static BYTE stem_en_li[] = "bcdeghkmnrt";

inline int stem_en_iv(BYTE l)
{
	register BYTE *v = stem_en_vowels;
	while (*v && *v != l) v++;
	return (*v == l) ? 1 : 0;
}

inline int stem_en_id(BYTE l)
{
	register BYTE *v = stem_en_doubles;
	while (*v && *v != l) v++;
	return (*v == l) ? 1 : 0;
}

inline int stem_en_il(BYTE l)
{
	register BYTE *v = stem_en_li;
	while (*v && *v != l) v++;
	return (*v == l) ? 1 : 0;
}

inline int stem_en_ivwxy(BYTE l)
{
	register BYTE *v = stem_en_vwxy;
	while (*v && *v != l) v++;
	return (*v == l) ? 1 : 0;
}

inline int stem_en_suffix(BYTE *word, int *len, int r,
	stem_table *table, int ntable)
{
	int i, j, k;

	for (i = 0; i < ntable; i++) {
		j = table[i].len-1;
		k = *len-1;
		if (j > k) continue;
		for (; j >= 0; k--, j--)
			if (word[k] != table[i].suffix[j]) break;
		if (j >= 0) continue;

		if (*len - table[i].len < r) return 1;

		*len -= table[i].nremove;
		word += *len;
		switch (table[i].nadd) {
			case 1:
				*word = table[i].add[0];
				break;
			case 2:
				*word++ = table[i].add[0];
				*word = table[i].add[1];
				break;
		}
		*len += table[i].nadd;
		return 1;
	}
	return 0;
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
			fprintf ( stdout, "\nStrong stem\n");
			fprintf ( stdout, (char*)word );
			return true;
		}
	}
	return false;
}

void stem_en ( BYTE * word )
{
	int i, j, len, r1, r2;

	len = (int)strlen((char*)word);
	if (len <= 2) {
		//HACK: Convert "ye" to "you."
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
	
	if (word[0] == 'y') word[0] = 'Y';
	for (i = 1; i < len; i++)
		if (word[i] == 'y' && stem_en_iv(word[i-1])) word[i] = 'Y';

	r1 = r2 = len;
	if (strncmp((char*)word, "gener", 5) == 0) {
		r1 = 5;
	} else {
		for (i = 0; i < len-1; i++)
			if (stem_en_iv(word[i]) && !stem_en_iv(word[i+1])) { r1 = i+2; break; }
	}
	for (i = r1; i < len-1; i++)
		if (stem_en_iv(word[i]) && !stem_en_iv(word[i+1])) { r2 = i+2; break; }

	#define W(p,c) (word[len-p] == c)
	#define SUFF2(c2,c1) (len >= 2 && W(1,c1) && W(2,c2))
	#define SUFF3(c3,c2,c1) (len >= 3 && W(1,c1) && W(2,c2) && W(3,c3))
	#define SUFF4(c4,c3,c2,c1) (len >= 4 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4))
	#define SUFF5(c5,c4,c3,c2,c1) (len >= 5 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5))
	#define SUFF6(c6,c5,c4,c3,c2,c1) (len >= 6 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) && W(6,c6))
	#define SUFF7(c7,c6,c5,c4,c3,c2,c1) (len >= 7 && W(1,c1) && W(2,c2) && W(3,c3) && W(4,c4) && W(5,c5) && W(6,c6) && W(7,c7))

	// *** STEP 1A ***

	if (SUFF4('s','s','e','s')) len -= 2;
	if (W(3,'i') && W(2,'e') && (W(1,'d') || W(1,'s')))
		len -= (len == 4) ? 1 : 2;
	if (W(1,'s') && !(W(2,'u') || W(2,'s'))) len--;

	// *** STEP 1B ***

	i = 0;
	for ( ;; )
	{
		if (SUFF3('e','e','d')) {
			if (len-3 >= r1) len--;
			break;
		}
		if (SUFF5('e','e','d','l','y')) {
			if (len-5 >= r1) len -= 3;
			break;
		}
		if (SUFF2('e','d')) { i = 2; break; }
		if (SUFF3('i','n','g')) { i = 3; break; }
		// Begin Early Modern English fix
		if (SUFF3('e','s','t')) { i = 3; break; }
		if (SUFF3('e','t','h')) { i = 3; break; }
		// End Early Modern English fix
		if (SUFF4('e','d','l','y')) { i = 4; break; }
		if (SUFF5('i','n','g','l','y')) { i = 5; break; }
		break;
	}
	if (i) for (j = 0; j < len-i; j++) if (stem_en_iv(word[j])) {
		len -= i;
		if (SUFF2('a','t') || SUFF2('b','l') || SUFF2('i','z')) {
			word[len++] = 'e'; break;
		}
		if (len >= 2 && word[len-1] == word[len-2] && stem_en_id(word[len-1])) {
			len--; break;
		}
		if ((len == 2 && (stem_en_iv(word[0]) && !stem_en_iv(word[1])))
			|| (len == r1 && !stem_en_iv(word[len-3]) && stem_en_iv(word[len-2]) && !stem_en_ivwxy(word[len-1])))
		{
			word[len++] = 'e';
		}
		break;
	}

	// *** STEP 1C ***

	if (len > 2 && (word[len-1] == 'y' || word[len-1] == 'Y')
		&& !stem_en_iv(word[len-2]))
	{
		word[len-1] = 'i';
	}

	// *** STEP 2 ***

	for ( ;; )
	{
		if (stem_en_suffix(word, &len, r1, en_step2, sizeof(en_step2)/sizeof(stem_table)))
			break;
		if (len-3 >= r1 && SUFF3('o','g','i')) { len -= 1; break; }

		if (len-2 >= r1 && SUFF2('l','i')) len -= 2; else break;
		if (len-2 >= r1 && SUFF2('a','l')) {
			len -= 2;
			if (len-5 >= r1 && SUFF5('a','t','i','o','n')) {
				len -= 3;
				word[len++] = 'e';
				break;
			}
			if (SUFF4('t','i','o','n')) break;
			len += 2;
		} else {
			if (!stem_en_il(word[len-1])) len += 2;
		}

		break;
	}

	// *** STEP 3 ***

	stem_en_suffix(word, &len, r1, en_step3, sizeof(en_step3)/sizeof(stem_table));

	// *** STEP 4 ***

	i = stem_en_suffix(word, &len, r2, en_step4, sizeof(en_step4)/sizeof(stem_table));
	if (!i && len-3 >= r2 && SUFF3('i','o','n') && (word[len-4] == 't' || word[len-4] == 's')) {
		len -= 3;
	}

	// *** STEP 5 ***
    
	if (len > r2 && word[len-1] == 'l' && word[len-2] == 'l') {
	   len--;
    } else {
        while (word[len-1] == 'e') {
            if (len > r2) { len--; break; }
            if (len <= r1) break;
            if (len > 3 && !stem_en_iv(word[len-4]) && stem_en_iv(word[len-3])
                && !stem_en_ivwxy(word[len-2])) break;
            if (len == 3 && stem_en_iv(word[0]) && !stem_en_iv(word[1])) break;
            len--;
            break;
        }
    }

	// *** FINALIZE ***

	word[len] = 0;
	for (i = 0; i < len; i++) if (word[i] == 'Y') word[i] = 'y';
	
	/// Testing the results.
	fprintf ( stdout, "\nWeak stem\n");
	fprintf ( stdout, (char*)word );
}

//
// $Id: sphinxstemen.cpp 1709 2009-02-27 10:30:10Z klirichek $
//
