#pragma once

#include <caml/custom.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>

#define fstValue(p) (*((struct Fst **) Data_custom_val(p)))
#define rngValue(p) (*((struct Rng **) Data_custom_val(p)))

CAMLprim value testFstLib(value filename);
CAMLprim value newFst(value rng);
void finalizeFst(value fst);
void finalizeRng(value rng);
CAMLprim value rand_float(value rng, value max);
CAMLprim value addState(value fst, value edit);
CAMLprim value setFinal(value fst, value state, value weight);
CAMLprim value setStart(value fst, value state);
CAMLprim value getStart(value fst);
CAMLprim value getBeta(value fst, value state);
CAMLprim value addArc(value fst, value stateFrom, value stateTo, value label, value weight);
CAMLprim value compose(value fstl, value fstr);
CAMLprim value union_(value fstl, value fstr);
CAMLprim value intersect_(value fstl, value fstr);
CAMLprim value minimize(value fst);
CAMLprim value determinize(value fst);
CAMLprim value concat(value fstl, value fstr);
CAMLprim value projectInput(value fst);
CAMLprim value projectOutput(value fst);
CAMLprim value shortestPath(value fst);
CAMLprim value writeToFile(value fst, value filename);
CAMLprim value readFromFile(value filename);
CAMLprim value getAllEdits(value fst);
CAMLprim value arcSort(value fst);
CAMLprim value normalize(value fst);
CAMLprim value sample(value fst);
CAMLprim value getBestEdits(value fst);
CAMLprim value getBest(value fst, value state);
double getEditProb(int n);
CAMLprim value reweightFst(value fst);