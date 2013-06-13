/*
formulaWrapper.c 2013.06.13 Y.Mizoguchi
*/

#include "Python.h"
extern float s0(float,float,float,float,float,float);
extern float s1(float,float,float,float,float,float);
extern float s2(float,float,float,float,float,float);

PyObject* formula_s(PyObject* self, PyObject* args)
{
  float a, b, c, d, e, f;
  if (!PyArg_ParseTuple(args, "ffffff", &a, &b, &c, &d, &e, &f))
		return NULL;
  return Py_BuildValue("[fff]", 
		       s0(a,b,c,d,e,f),
		       s1(a,b,c,d,e,f),
		       s2(a,b,c,d,e,f));
}

PyObject* formula_s0(PyObject* self, PyObject* args)
{
  float a, b, c, d, e, f;
  if (!PyArg_ParseTuple(args, "ffffff", &a, &b, &c, &d, &e, &f))
		return NULL;
  return Py_BuildValue("f", s0(a,b,c,d,e,f));
}

static PyMethodDef formulamethods[] = {
	{"s", formula_s, METH_VARARGS},
	{"s0", formula_s0, METH_VARARGS},
	{NULL},
};

void initformula()
{
	Py_InitModule("formula", formulamethods);
}
