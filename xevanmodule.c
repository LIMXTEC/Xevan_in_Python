#include <Python.h>

#include "xevanhash.h"

static PyObject *xevan_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    xevan_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    xevan_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef xevanMethods[] = {
    { "getPoWHash", xevan_getpowhash, METH_VARARGS, "Returns the proof of work hash using x11 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef xevanModule = {
    PyModuleDef_HEAD_INIT,
    "xevan_hash",
    "...",
    -1,
    xevanMethods
};

PyMODINIT_FUNC PyInit_xevan_hash(void) {
    return PyModule_Create(&xevanModule);
}

#else

PyMODINIT_FUNC initxevan_hash(void) {
    (void) Py_InitModule("xevan_hash", xevanMethods);
}
#endif
