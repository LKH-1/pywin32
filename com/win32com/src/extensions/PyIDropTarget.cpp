// This file implements the IDropTarget Interface and Gateway for Python.
// Generated by makegw.py

// @doc
#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "PyIDropTarget.h"

static BOOL PyObject_AsPOINTL(PyObject *ob, POINTL *pp)
{
	return PyArg_ParseTuple(ob, "ll", &pp->x, &pp->y);
}

static PyObject *PyObject_FromPOINTL(POINTL &p)
{
	return Py_BuildValue("ii", p.x, p.y);
}
// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIDropTarget::PyIDropTarget(IUnknown *pdisp):
	PyIUnknown(pdisp)
{
	ob_type = &type;
}

PyIDropTarget::~PyIDropTarget()
{
}

/* static */ IDropTarget *PyIDropTarget::GetI(PyObject *self)
{
	return (IDropTarget *)PyIUnknown::GetI(self);
}

// @pymethod int|PyIDropTarget|DragEnter|Called when an object is initially dragged into a window
// @rdesc Your implementation of this function should return a shellcon.DROPEFFECT_* value indicating if the object can be accepted
PyObject *PyIDropTarget::DragEnter(PyObject *self, PyObject *args)
{
	IDropTarget *pIDT = GetI(self);
	if ( pIDT == NULL )
		return NULL;
	// @pyparm <o PyIDataObject>|pDataObj||IDataObject interface that contains the object being dragged
	// @pyparm int|grfKeyState||Combination of win32con.MK_* flags containing keyboard modifier state
	POINTL pt;
	PyObject *obpt;
	// @pyparm (int, int)|pt||(x,y) Screen coordinates of cursor
	PyObject *obpDataObj;
	IDataObject *pDataObj;
	DWORD grfKeyState;
        DWORD dwEffect;
	// @pyparm int|pdwEffect||shellcon.DROPEFFECT_* value
	if ( !PyArg_ParseTuple(args, "OlOl:DragEnter", &obpDataObj, &grfKeyState, &obpt, &dwEffect) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obpDataObj, IID_IDataObject, (void **)&pDataObj, TRUE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (bPythonIsHappy && !PyObject_AsPOINTL( obpt, &pt )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIDT->DragEnter( pDataObj, grfKeyState, pt, &dwEffect );
	if (pDataObj) pDataObj->Release();
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIDT, IID_IDropTarget );
	return PyInt_FromLong(dwEffect);
}

// @pymethod int|PyIDropTarget|DragOver|Called as the dragged object moves over the window
// @rdesc Your implementation of this function should return a shellcon.DROPEFFECT_* value indicating if the
//	object can be accepted at the current position
PyObject *PyIDropTarget::DragOver(PyObject *self, PyObject *args)
{
	IDropTarget *pIDT = GetI(self);
	if ( pIDT == NULL )
		return NULL;
	// @pyparm int|grfKeyState||Combination of win32con.MK_* flags containing keyboard modifier state
	POINTL pt;
	PyObject *obpt;
	// @pyparm (int, int)|pt||(x,y) Screen coordinates of cursor
	DWORD dwEffect;
	// @pyparm int|pdwEffect||shellcon.DROPEFFECT_* value
	DWORD grfKeyState;
	if ( !PyArg_ParseTuple(args, "lOl:DragOver", &grfKeyState, &obpt, &dwEffect) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyObject_AsPOINTL( obpt, &pt )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIDT->DragOver( grfKeyState, pt, &dwEffect );
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIDT, IID_IDropTarget );
	return PyInt_FromLong(dwEffect);
}

// @pymethod |PyIDropTarget|DragLeave|Called as the object is dragged back out of the window
PyObject *PyIDropTarget::DragLeave(PyObject *self, PyObject *args)
{
	IDropTarget *pIDT = GetI(self);
	if ( pIDT == NULL )
		return NULL;
	if ( !PyArg_ParseTuple(args, ":DragLeave") )
		return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIDT->DragLeave( );

	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIDT, IID_IDropTarget );
	Py_INCREF(Py_None);
	return Py_None;

}

// @pymethod int|PyIDropTarget|Drop|Called when the object is dropped onto the window
// @rdesc Your implementation of this function should return one of the shellcon.DROPEFFECT_* values
PyObject *PyIDropTarget::Drop(PyObject *self, PyObject *args)
{
	IDropTarget *pIDT = GetI(self);
	if ( pIDT == NULL )
		return NULL;
	// @pyparm <o PyIDataObject>|pDataObj||IDataObject interface containing the dropped object
	// @pyparm int|grfKeyState||Combination of win32con.MK_* flags containing keyboard modifier state
	POINTL pt;
	PyObject *obpt;
	// @pyparm (int, int)|pt||(x,y) Screen coordinates of cursor
	DWORD dwEffect;
	// @pyparm int|dwEffect||shellcon.DROPEFFECT_* value
	PyObject *obpDataObj;
	IDataObject * pDataObj;
	DWORD grfKeyState;
	if ( !PyArg_ParseTuple(args, "OlOi:Drop", &obpDataObj, &grfKeyState, &obpt, &dwEffect) )
		return NULL;
	BOOL bPythonIsHappy = TRUE;
	if (bPythonIsHappy && !PyCom_InterfaceFromPyInstanceOrObject(obpDataObj, IID_IDataObject, (void **)&pDataObj, TRUE /* bNoneOK */))
		 bPythonIsHappy = FALSE;
	if (bPythonIsHappy && !PyObject_AsPOINTL( obpt, &pt )) bPythonIsHappy = FALSE;
	if (!bPythonIsHappy) return NULL;
	HRESULT hr;
	PY_INTERFACE_PRECALL;
	hr = pIDT->Drop( pDataObj, grfKeyState, pt, &dwEffect );
	if (pDataObj) pDataObj->Release();
	PY_INTERFACE_POSTCALL;

	if ( FAILED(hr) )
		return PyCom_BuildPyException(hr, pIDT, IID_IDropTarget );
	return PyInt_FromLong(dwEffect);

}

// @object PyIDropTarget|Interface that acts as a target of OLE drag and drop operations
static struct PyMethodDef PyIDropTarget_methods[] =
{
	{ "DragEnter", PyIDropTarget::DragEnter, 1 }, // @pymeth DragEnter|Called when an object is initially dragged into a window
	{ "DragOver", PyIDropTarget::DragOver, 1 }, // @pymeth DragOver|Called as the dragged object moves over the window
	{ "DragLeave", PyIDropTarget::DragLeave, 1 }, // @pymeth DragLeave|Called as the object is dragged back out of the window
	{ "Drop", PyIDropTarget::Drop, 1 }, // @pymeth Drop|Called when the object is dropped onto the window
	{ NULL }
};

PyComTypeObject PyIDropTarget::type("PyIDropTarget",
		&PyIUnknown::type,
		sizeof(PyIDropTarget),
		PyIDropTarget_methods,
		GET_PYCOM_CTOR(PyIDropTarget));
// ---------------------------------------------------
//
// Gateway Implementation
STDMETHODIMP PyGDropTarget::DragEnter(
		/* [unique][in] */ IDataObject * pDataObj,
		/* [in] */ DWORD grfKeyState,
		/* [in] */ POINTL pt,
		/* [out][in] */ DWORD * pdwEffect)
{
	static const char *method_name = "DragEnter";
	PY_GATEWAY_METHOD;
	PyObject *obpt = PyObject_FromPOINTL(pt);
	if (obpt==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	PyObject *obpDataObj;
	obpDataObj = PyCom_PyObjectFromIUnknown(pDataObj, IID_IDataObject, TRUE);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result, "OlOl", obpDataObj, grfKeyState, obpt, *pdwEffect);
	Py_XDECREF(obpDataObj);
	Py_DECREF(obpt);
	if (FAILED(hr)) return hr;
	if (result && PyInt_Check(result))
		*pdwEffect = PyInt_AsLong(result);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDropTarget::DragOver(
		/* [in] */ DWORD grfKeyState,
		/* [in] */ POINTL pt,
		/* [out][in] */ DWORD * pdwEffect)
{
	static const char *method_name = "DragOver";
	PY_GATEWAY_METHOD;
	PyObject *obpt = PyObject_FromPOINTL(pt);
	if (obpt==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result, "lOl", grfKeyState, obpt, *pdwEffect);
	Py_DECREF(obpt);
	if (FAILED(hr)) return hr;
	if (result && PyInt_Check(result))
		*pdwEffect = PyInt_AsLong(result);
	Py_DECREF(result);
	return hr;
}

STDMETHODIMP PyGDropTarget::DragLeave(
		void)
{
	PY_GATEWAY_METHOD;
	HRESULT hr=InvokeViaPolicy("DragLeave", NULL);
	return hr;
}

STDMETHODIMP PyGDropTarget::Drop(
		/* [unique][in] */ IDataObject * pDataObj,
		/* [in] */ DWORD grfKeyState,
		/* [in] */ POINTL pt,
		/* [out][in] */ DWORD * pdwEffect)
{
	static const char *method_name = "Drop";
	PY_GATEWAY_METHOD;
	PyObject *obpt = PyObject_FromPOINTL(pt);
	if (obpt==NULL) return MAKE_PYCOM_GATEWAY_FAILURE_CODE(method_name);
	PyObject *obpDataObj;
	obpDataObj = PyCom_PyObjectFromIUnknown(pDataObj, IID_IDataObject, TRUE);
	PyObject *result;
	HRESULT hr=InvokeViaPolicy(method_name, &result, "OlOl", obpDataObj, grfKeyState, obpt, *pdwEffect);
	Py_XDECREF(obpDataObj);
	Py_DECREF(obpt);
	if (FAILED(hr)) return hr;
	if (result && PyInt_Check(result))
		*pdwEffect = PyInt_AsLong(result);
	Py_DECREF(result);
	return hr;
}
