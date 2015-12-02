// This file implements the IEnumDebugExpressionContexts Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PyIEnumDebugExpressionContexts.h"

// @doc - This file contains autoduck documentation

// ---------------------------------------------------
//
// Interface Implementation

PyIEnumDebugExpressionContexts::PyIEnumDebugExpressionContexts(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIEnumDebugExpressionContexts::~PyIEnumDebugExpressionContexts()
{
}

/* static */ IEnumDebugExpressionContexts *PyIEnumDebugExpressionContexts::GetI(PyObject *self)
{
	return (IEnumDebugExpressionContexts *)PyIUnknown::GetI(self);
}

// @pymethod object|PyIEnumDebugExpressionContexts|Next|Retrieves a specified number of items in the enumeration sequence.
PyObject *PyIEnumDebugExpressionContexts::Next(PyObject *self, PyObject *args)
{
	long celt = 1;
	// @pyparm int|num|1|Number of items to retrieve.
	if ( !PyArg_ParseTuple(args, "|l:Next", &celt) )
		return NULL;

	IEnumDebugExpressionContexts *pIEDebugExpressionContexts = GetI(self);
	if ( pIEDebugExpressionContexts == NULL )
		return NULL;

	IDebugExpressionContext **rgVar = new IDebugExpressionContext *[celt];
	if ( rgVar == NULL ) {
		PyErr_SetString(PyExc_MemoryError, "allocating result DebugExpressionContexts");
		return NULL;
	}

	int i;
/*	for ( i = celt; i--; )
		// *** possibly init each structure element???
*/

	ULONG celtFetched = 0;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIEDebugExpressionContexts->Next(celt, rgVar, &celtFetched);
	PY_INTERFACE_POSTCALL;
	if (  HRESULT_CODE(hr) != ERROR_NO_MORE_ITEMS && FAILED(hr) )
	{
		delete [] rgVar;
		return OleSetOleError(hr);
	}

	PyObject *result = PyTuple_New(celtFetched);
	if ( result != NULL )
	{
		for ( i = celtFetched; i--; )
		{
			PyObject *ob = PyCom_PyObjectFromIUnknown(rgVar[i], IID_IDebugExpressionContext, FALSE);
			rgVar[i] = NULL;
			if ( ob == NULL )
			{
				Py_DECREF(result);
				result = NULL;
				break;
			}
			PyTuple_SET_ITEM(result, i, ob);
		}
	}
	for ( i = celtFetched; i--; ) PYCOM_RELEASE(rgVar[i]);
	delete [] rgVar;
	return result;
}

// @pymethod |PyIEnumDebugExpressionContexts|Skip|Skips over the next specified elementes.
PyObject *PyIEnumDebugExpressionContexts::Skip(PyObject *self, PyObject *args)
{
	long celt;
	if ( !PyArg_ParseTuple(args, "l:Skip", &celt) )
		return NULL;

	IEnumDebugExpressionContexts *pIEDebugExpressionContexts = GetI(self);
	if ( pIEDebugExpressionContexts == NULL )
		return NULL;

	PY_INTERFACE_PRECALL;
	HRESULT hr = pIEDebugExpressionContexts->Skip(celt);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);

	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod |PyIEnumDebugExpressionContexts|Reset|Resets the enumeration sequence to the beginning.
PyObject *PyIEnumDebugExpressionContexts::Reset(PyObject *self, PyObject *args)
{
	if ( !PyArg_ParseTuple(args, ":Reset") )
		return NULL;

	IEnumDebugExpressionContexts *pIEDebugExpressionContexts = GetI(self);
	if ( pIEDebugExpressionContexts == NULL )
		return NULL;

	PY_INTERFACE_PRECALL;
	HRESULT hr = pIEDebugExpressionContexts->Reset();
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);

	Py_INCREF(Py_None);
	return Py_None;
}

// @pymethod <o PyIEnumDebugExpressionContexts>|PyIEnumDebugExpressionContexts|Clone|Creates another enumerator that contains the same enumeration state as the current one
PyObject *PyIEnumDebugExpressionContexts::Clone(PyObject *self, PyObject *args)
{
	if ( !PyArg_ParseTuple(args, ":Clone") )
		return NULL;

	IEnumDebugExpressionContexts *pIEDebugExpressionContexts = GetI(self);
	if ( pIEDebugExpressionContexts == NULL )
		return NULL;

	IEnumDebugExpressionContexts *pClone;
	PY_INTERFACE_PRECALL;
	HRESULT hr = pIEDebugExpressionContexts->Clone(&pClone);
	PY_INTERFACE_POSTCALL;
	if ( FAILED(hr) )
		return OleSetOleError(hr);

	return PyCom_PyObjectFromIUnknown(pClone, IID_IEnumDebugExpressionContexts, FALSE);
}

// @object PyIEnumDebugExpressionContexts|A Python interface to IEnumDebugExpressionContexts
static struct PyMethodDef PyIEnumDebugExpressionContexts_methods[] =
{
	{ "Next", PyIEnumDebugExpressionContexts::Next, 1 },    // @pymeth Next|Retrieves a specified number of items in the enumeration sequence.
	{ "Skip", PyIEnumDebugExpressionContexts::Skip, 1 },	// @pymeth Skip|Skips over the next specified elementes.
	{ "Reset", PyIEnumDebugExpressionContexts::Reset, 1 },	// @pymeth Reset|Resets the enumeration sequence to the beginning.
	{ "Clone", PyIEnumDebugExpressionContexts::Clone, 1 },	// @pymeth Clone|Creates another enumerator that contains the same enumeration state as the current one.
	{ NULL }
};

PyComTypeObject PyIEnumDebugExpressionContexts::type("PyIEnumDebugExpressionContexts",
		&PyIUnknown::type,
		sizeof(PyIEnumDebugExpressionContexts),
		PyIEnumDebugExpressionContexts_methods,
		GET_PYCOM_CTOR(PyIEnumDebugExpressionContexts));

// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGEnumDebugExpressionContexts::Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IDebugExpressionContext __RPC_FAR * __RPC_FAR *rgVar,
            /* [out] */ ULONG __RPC_FAR *pCeltFetched)
{
	PY_GATEWAY_METHOD;
	PyObject *result;
	Py_ssize_t len;
	HRESULT hr = InvokeViaPolicy("Next", &result, "i", celt);
	if ( FAILED(hr) )
		return hr;

	if ( !PySequence_Check(result) )
		goto error;
	len = PyObject_Length(result);
	if ( len == -1 )
		goto error;
	if ( len > (Py_ssize_t)celt)
		len = celt;

	if ( pCeltFetched )
		*pCeltFetched = PyWin_SAFE_DOWNCAST(len, Py_ssize_t, ULONG);

	Py_ssize_t i;
	for ( i = 0; i < len; ++i )
	{
		PyObject *ob = PySequence_GetItem(result, i);
		if ( ob == NULL )
			goto error;

		if ( !PyCom_InterfaceFromPyObject(ob, IID_IDebugExpressionContext, (void **)&rgVar[i], FALSE) )
		{
			Py_DECREF(result);
			return PyCom_SetCOMErrorFromPyException(IID_IEnumDebugExpressionContexts);
		}
	}

	Py_DECREF(result);

	return len < (Py_ssize_t)celt ? S_FALSE : S_OK;

  error:
	PyErr_Clear();	// just in case
	Py_DECREF(result);
	return PyCom_SetCOMErrorFromSimple(E_FAIL, IID_IEnumDebugExpressionContexts, "Next() did not return a sequence of objects");
}

STDMETHODIMP PyGEnumDebugExpressionContexts::Skip( 
            /* [in] */ ULONG celt)
{
	PY_GATEWAY_METHOD;
	return InvokeViaPolicy("Skip", NULL, "i", celt);
}

STDMETHODIMP PyGEnumDebugExpressionContexts::Reset(void)
{
	PY_GATEWAY_METHOD;
	return InvokeViaPolicy("Reset");
}

STDMETHODIMP PyGEnumDebugExpressionContexts::Clone( 
            /* [out] */ IEnumDebugExpressionContexts __RPC_FAR *__RPC_FAR *ppEnum)
{
	PY_GATEWAY_METHOD;
	PyObject * result;
	HRESULT hr = InvokeViaPolicy("Clone", &result);
	if ( FAILED(hr) )
		return hr;

	/*
	** Make sure we have the right kind of object: we should have some kind
	** of IUnknown subclass wrapped into a PyIUnknown instance.
	*/
	if ( !PyIBase::is_object(result, &PyIUnknown::type) )
	{
		/* the wrong kind of object was returned to us */
		Py_DECREF(result);
		return PyCom_SetCOMErrorFromSimple(E_FAIL, IID_IEnumDebugExpressionContexts);
	}

	/*
	** Get the IUnknown out of the thing. note that the Python ob maintains
	** a reference, so we don't have to explicitly AddRef() here.
	*/
	IUnknown *punk = ((PyIUnknown *)result)->m_obj;
	if ( !punk )
	{
		/* damn. the object was released. */
		Py_DECREF(result);
		return PyCom_SetCOMErrorFromSimple(E_FAIL, IID_IEnumDebugExpressionContexts);
	}

	/*
	** Get the interface we want. note it is returned with a refcount.
	** This QI is actually going to instantiate a PyGEnumDebugExpressionContexts.
	*/
	Py_BEGIN_ALLOW_THREADS
	hr = punk->QueryInterface(IID_IEnumDebugExpressionContexts, (LPVOID *)ppEnum);
	Py_END_ALLOW_THREADS

	/* done with the result; this DECREF is also for <punk> */
	Py_DECREF(result);

	return PyCom_SetCOMErrorFromSimple(hr, IID_IEnumDebugExpressionContexts);
}