

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for Rubberduck.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __Rubberduck_h__
#define __Rubberduck_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDockableWindowHost_FWD_DEFINED__
#define __IDockableWindowHost_FWD_DEFINED__
typedef interface IDockableWindowHost IDockableWindowHost;

#endif 	/* __IDockableWindowHost_FWD_DEFINED__ */


#ifndef __IAssert_FWD_DEFINED__
#define __IAssert_FWD_DEFINED__
typedef interface IAssert IAssert;

#endif 	/* __IAssert_FWD_DEFINED__ */


#ifndef __IFake_FWD_DEFINED__
#define __IFake_FWD_DEFINED__
typedef interface IFake IFake;

#endif 	/* __IFake_FWD_DEFINED__ */


#ifndef __IFakesProvider_FWD_DEFINED__
#define __IFakesProvider_FWD_DEFINED__
typedef interface IFakesProvider IFakesProvider;

#endif 	/* __IFakesProvider_FWD_DEFINED__ */


#ifndef __IStub_FWD_DEFINED__
#define __IStub_FWD_DEFINED__
typedef interface IStub IStub;

#endif 	/* __IStub_FWD_DEFINED__ */


#ifndef __IVerify_FWD_DEFINED__
#define __IVerify_FWD_DEFINED__
typedef interface IVerify IVerify;

#endif 	/* __IVerify_FWD_DEFINED__ */


#ifndef ___Extension_FWD_DEFINED__
#define ___Extension_FWD_DEFINED__

#ifdef __cplusplus
typedef class _Extension _Extension;
#else
typedef struct _Extension _Extension;
#endif /* __cplusplus */

#endif 	/* ___Extension_FWD_DEFINED__ */


#ifndef ___DockableWindowHost_FWD_DEFINED__
#define ___DockableWindowHost_FWD_DEFINED__

#ifdef __cplusplus
typedef class _DockableWindowHost _DockableWindowHost;
#else
typedef struct _DockableWindowHost _DockableWindowHost;
#endif /* __cplusplus */

#endif 	/* ___DockableWindowHost_FWD_DEFINED__ */


#ifndef __AssertClass_FWD_DEFINED__
#define __AssertClass_FWD_DEFINED__

#ifdef __cplusplus
typedef class AssertClass AssertClass;
#else
typedef struct AssertClass AssertClass;
#endif /* __cplusplus */

#endif 	/* __AssertClass_FWD_DEFINED__ */


#ifndef __FakesProvider_FWD_DEFINED__
#define __FakesProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class FakesProvider FakesProvider;
#else
typedef struct FakesProvider FakesProvider;
#endif /* __cplusplus */

#endif 	/* __FakesProvider_FWD_DEFINED__ */


#ifndef __PermissiveAssertClass_FWD_DEFINED__
#define __PermissiveAssertClass_FWD_DEFINED__

#ifdef __cplusplus
typedef class PermissiveAssertClass PermissiveAssertClass;
#else
typedef struct PermissiveAssertClass PermissiveAssertClass;
#endif /* __cplusplus */

#endif 	/* __PermissiveAssertClass_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Rubberduck_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_Rubberduck_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Rubberduck_0000_0000_v0_0_s_ifspec;


#ifndef __Rubberduck_LIBRARY_DEFINED__
#define __Rubberduck_LIBRARY_DEFINED__

/* library Rubberduck */
/* [helpstring][custom][version][uuid] */ 













EXTERN_C const IID LIBID_Rubberduck;

#ifndef __IDockableWindowHost_INTERFACE_DEFINED__
#define __IDockableWindowHost_INTERFACE_DEFINED__

/* interface IDockableWindowHost */
/* [object][restricted][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IDockableWindowHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f698-43f0-3b33-b105-9b8188a6f040")
    IDockableWindowHost : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddUserControl( 
            /* [in] */ /* external definition not present */ _UserControl *control,
            /* [in] */ long vbeHwnd) = 0;
        
        virtual /* [custom][id] */ HRESULT STDMETHODCALLTYPE Release_2( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDockableWindowHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDockableWindowHost * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDockableWindowHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDockableWindowHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDockableWindowHost * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDockableWindowHost * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDockableWindowHost * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDockableWindowHost * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddUserControl )( 
            IDockableWindowHost * This,
            /* [in] */ /* external definition not present */ _UserControl *control,
            /* [in] */ long vbeHwnd);
        
        /* [custom][id] */ HRESULT ( STDMETHODCALLTYPE *Release_2 )( 
            IDockableWindowHost * This);
        
        END_INTERFACE
    } IDockableWindowHostVtbl;

    interface IDockableWindowHost
    {
        CONST_VTBL struct IDockableWindowHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDockableWindowHost_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDockableWindowHost_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDockableWindowHost_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDockableWindowHost_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDockableWindowHost_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDockableWindowHost_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDockableWindowHost_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDockableWindowHost_AddUserControl(This,control,vbeHwnd)	\
    ( (This)->lpVtbl -> AddUserControl(This,control,vbeHwnd) ) 

#define IDockableWindowHost_Release_2(This)	\
    ( (This)->lpVtbl -> Release_2(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDockableWindowHost_INTERFACE_DEFINED__ */


#ifndef __IAssert_INTERFACE_DEFINED__
#define __IAssert_INTERFACE_DEFINED__

/* interface IAssert */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IAssert;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f7db-43f0-3b33-b105-9b8188a6f040")
    IAssert : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsTrue( 
            /* [in] */ VARIANT_BOOL Condition,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsFalse( 
            /* [in] */ VARIANT_BOOL Condition,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Inconclusive( 
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Fail( 
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Succeed( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsNothing( 
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsNotNothing( 
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreEqual( 
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreNotEqual( 
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreSame( 
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreNotSame( 
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SequenceEquals( 
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NotSequenceEquals( 
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAssertVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAssert * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAssert * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAssert * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAssert * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAssert * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAssert * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAssert * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsTrue )( 
            IAssert * This,
            /* [in] */ VARIANT_BOOL Condition,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsFalse )( 
            IAssert * This,
            /* [in] */ VARIANT_BOOL Condition,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Inconclusive )( 
            IAssert * This,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Fail )( 
            IAssert * This,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Succeed )( 
            IAssert * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsNothing )( 
            IAssert * This,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsNotNothing )( 
            IAssert * This,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreEqual )( 
            IAssert * This,
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreNotEqual )( 
            IAssert * This,
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreSame )( 
            IAssert * This,
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreNotSame )( 
            IAssert * This,
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SequenceEquals )( 
            IAssert * This,
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NotSequenceEquals )( 
            IAssert * This,
            /* [in] */ VARIANT Expected,
            /* [in] */ VARIANT Actual,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        END_INTERFACE
    } IAssertVtbl;

    interface IAssert
    {
        CONST_VTBL struct IAssertVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAssert_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAssert_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAssert_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAssert_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAssert_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAssert_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAssert_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAssert_IsTrue(This,Condition,Message)	\
    ( (This)->lpVtbl -> IsTrue(This,Condition,Message) ) 

#define IAssert_IsFalse(This,Condition,Message)	\
    ( (This)->lpVtbl -> IsFalse(This,Condition,Message) ) 

#define IAssert_Inconclusive(This,Message)	\
    ( (This)->lpVtbl -> Inconclusive(This,Message) ) 

#define IAssert_Fail(This,Message)	\
    ( (This)->lpVtbl -> Fail(This,Message) ) 

#define IAssert_Succeed(This)	\
    ( (This)->lpVtbl -> Succeed(This) ) 

#define IAssert_IsNothing(This,Value,Message)	\
    ( (This)->lpVtbl -> IsNothing(This,Value,Message) ) 

#define IAssert_IsNotNothing(This,Value,Message)	\
    ( (This)->lpVtbl -> IsNotNothing(This,Value,Message) ) 

#define IAssert_AreEqual(This,Expected,Actual,Message)	\
    ( (This)->lpVtbl -> AreEqual(This,Expected,Actual,Message) ) 

#define IAssert_AreNotEqual(This,Expected,Actual,Message)	\
    ( (This)->lpVtbl -> AreNotEqual(This,Expected,Actual,Message) ) 

#define IAssert_AreSame(This,Expected,Actual,Message)	\
    ( (This)->lpVtbl -> AreSame(This,Expected,Actual,Message) ) 

#define IAssert_AreNotSame(This,Expected,Actual,Message)	\
    ( (This)->lpVtbl -> AreNotSame(This,Expected,Actual,Message) ) 

#define IAssert_SequenceEquals(This,Expected,Actual,Message)	\
    ( (This)->lpVtbl -> SequenceEquals(This,Expected,Actual,Message) ) 

#define IAssert_NotSequenceEquals(This,Expected,Actual,Message)	\
    ( (This)->lpVtbl -> NotSequenceEquals(This,Expected,Actual,Message) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAssert_INTERFACE_DEFINED__ */


#ifndef __IFake_INTERFACE_DEFINED__
#define __IFake_INTERFACE_DEFINED__

/* interface IFake */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IFake;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f7df-43f0-3b33-b105-9b8188a6f040")
    IFake : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Verify( 
            /* [retval][out] */ IVerify **pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AssignsByRef( 
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RaisesError( 
            /* [defaultvalue][optional][in] */ long Number = 0,
            /* [defaultvalue][optional][in] */ BSTR Description = (BSTR)L"") = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PassThrough( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_PassThrough( 
            /* [in] */ VARIANT_BOOL pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Returns( 
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ long Invocation = -1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReturnsWhen( 
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Argument,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ long Invocation = -1) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFakeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFake * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFake * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFake * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFake * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFake * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFake * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFake * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Verify )( 
            IFake * This,
            /* [retval][out] */ IVerify **pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AssignsByRef )( 
            IFake * This,
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RaisesError )( 
            IFake * This,
            /* [defaultvalue][optional][in] */ long Number,
            /* [defaultvalue][optional][in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PassThrough )( 
            IFake * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PassThrough )( 
            IFake * This,
            /* [in] */ VARIANT_BOOL pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Returns )( 
            IFake * This,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ long Invocation);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReturnsWhen )( 
            IFake * This,
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Argument,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ long Invocation);
        
        END_INTERFACE
    } IFakeVtbl;

    interface IFake
    {
        CONST_VTBL struct IFakeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFake_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFake_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFake_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFake_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFake_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFake_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFake_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFake_get_Verify(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Verify(This,pRetVal) ) 

#define IFake_AssignsByRef(This,Parameter,Value)	\
    ( (This)->lpVtbl -> AssignsByRef(This,Parameter,Value) ) 

#define IFake_RaisesError(This,Number,Description)	\
    ( (This)->lpVtbl -> RaisesError(This,Number,Description) ) 

#define IFake_get_PassThrough(This,pRetVal)	\
    ( (This)->lpVtbl -> get_PassThrough(This,pRetVal) ) 

#define IFake_put_PassThrough(This,pRetVal)	\
    ( (This)->lpVtbl -> put_PassThrough(This,pRetVal) ) 

#define IFake_Returns(This,Value,Invocation)	\
    ( (This)->lpVtbl -> Returns(This,Value,Invocation) ) 

#define IFake_ReturnsWhen(This,Parameter,Argument,Value,Invocation)	\
    ( (This)->lpVtbl -> ReturnsWhen(This,Parameter,Argument,Value,Invocation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFake_INTERFACE_DEFINED__ */


#ifndef __IFakesProvider_INTERFACE_DEFINED__
#define __IFakesProvider_INTERFACE_DEFINED__

/* interface IFakesProvider */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IFakesProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f7de-43f0-3b33-b105-9b8188a6f040")
    IFakesProvider : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MsgBox( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_InputBox( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Beep( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Environ( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Timer( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DoEvents( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Shell( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SendKeys( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Kill( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MkDir( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_RmDir( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ChDir( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ChDrive( 
            /* [retval][out] */ IStub **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CurDir( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Now( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Time( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Date( 
            /* [retval][out] */ IFake **pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFakesProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFakesProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFakesProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFakesProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFakesProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFakesProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFakesProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFakesProvider * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MsgBox )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_InputBox )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Beep )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Environ )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Timer )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DoEvents )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Shell )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SendKeys )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Kill )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_MkDir )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RmDir )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ChDir )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ChDrive )( 
            IFakesProvider * This,
            /* [retval][out] */ IStub **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CurDir )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Now )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Time )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Date )( 
            IFakesProvider * This,
            /* [retval][out] */ IFake **pRetVal);
        
        END_INTERFACE
    } IFakesProviderVtbl;

    interface IFakesProvider
    {
        CONST_VTBL struct IFakesProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFakesProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFakesProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFakesProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFakesProvider_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFakesProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFakesProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFakesProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFakesProvider_get_MsgBox(This,pRetVal)	\
    ( (This)->lpVtbl -> get_MsgBox(This,pRetVal) ) 

#define IFakesProvider_get_InputBox(This,pRetVal)	\
    ( (This)->lpVtbl -> get_InputBox(This,pRetVal) ) 

#define IFakesProvider_get_Beep(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Beep(This,pRetVal) ) 

#define IFakesProvider_get_Environ(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Environ(This,pRetVal) ) 

#define IFakesProvider_get_Timer(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Timer(This,pRetVal) ) 

#define IFakesProvider_get_DoEvents(This,pRetVal)	\
    ( (This)->lpVtbl -> get_DoEvents(This,pRetVal) ) 

#define IFakesProvider_get_Shell(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Shell(This,pRetVal) ) 

#define IFakesProvider_get_SendKeys(This,pRetVal)	\
    ( (This)->lpVtbl -> get_SendKeys(This,pRetVal) ) 

#define IFakesProvider_get_Kill(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Kill(This,pRetVal) ) 

#define IFakesProvider_get_MkDir(This,pRetVal)	\
    ( (This)->lpVtbl -> get_MkDir(This,pRetVal) ) 

#define IFakesProvider_get_RmDir(This,pRetVal)	\
    ( (This)->lpVtbl -> get_RmDir(This,pRetVal) ) 

#define IFakesProvider_get_ChDir(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ChDir(This,pRetVal) ) 

#define IFakesProvider_get_ChDrive(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ChDrive(This,pRetVal) ) 

#define IFakesProvider_get_CurDir(This,pRetVal)	\
    ( (This)->lpVtbl -> get_CurDir(This,pRetVal) ) 

#define IFakesProvider_get_Now(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Now(This,pRetVal) ) 

#define IFakesProvider_get_Time(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Time(This,pRetVal) ) 

#define IFakesProvider_get_Date(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Date(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFakesProvider_INTERFACE_DEFINED__ */


#ifndef __IStub_INTERFACE_DEFINED__
#define __IStub_INTERFACE_DEFINED__

/* interface IStub */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IStub;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f7e1-43f0-3b33-b105-9b8188a6f040")
    IStub : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Verify( 
            /* [retval][out] */ IVerify **pRetVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AssignsByRef( 
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RaisesError( 
            /* [defaultvalue][optional][in] */ long Number = 0,
            /* [defaultvalue][optional][in] */ BSTR Description = (BSTR)L"") = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PassThrough( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_PassThrough( 
            /* [in] */ VARIANT_BOOL pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IStubVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IStub * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IStub * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IStub * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IStub * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IStub * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IStub * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IStub * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Verify )( 
            IStub * This,
            /* [retval][out] */ IVerify **pRetVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AssignsByRef )( 
            IStub * This,
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RaisesError )( 
            IStub * This,
            /* [defaultvalue][optional][in] */ long Number,
            /* [defaultvalue][optional][in] */ BSTR Description);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PassThrough )( 
            IStub * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_PassThrough )( 
            IStub * This,
            /* [in] */ VARIANT_BOOL pRetVal);
        
        END_INTERFACE
    } IStubVtbl;

    interface IStub
    {
        CONST_VTBL struct IStubVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStub_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IStub_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IStub_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IStub_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IStub_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IStub_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IStub_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IStub_get_Verify(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Verify(This,pRetVal) ) 

#define IStub_AssignsByRef(This,Parameter,Value)	\
    ( (This)->lpVtbl -> AssignsByRef(This,Parameter,Value) ) 

#define IStub_RaisesError(This,Number,Description)	\
    ( (This)->lpVtbl -> RaisesError(This,Number,Description) ) 

#define IStub_get_PassThrough(This,pRetVal)	\
    ( (This)->lpVtbl -> get_PassThrough(This,pRetVal) ) 

#define IStub_put_PassThrough(This,pRetVal)	\
    ( (This)->lpVtbl -> put_PassThrough(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IStub_INTERFACE_DEFINED__ */


#ifndef __IVerify_INTERFACE_DEFINED__
#define __IVerify_INTERFACE_DEFINED__

/* interface IVerify */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IVerify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f7e0-43f0-3b33-b105-9b8188a6f040")
    IVerify : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AtLeast( 
            /* [in] */ long Invocations,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AtLeastOnce( 
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AtMost( 
            /* [in] */ long Invocations,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AtMostOnce( 
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Between( 
            /* [in] */ long Minimum,
            /* [in] */ long Maximum,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exactly( 
            /* [in] */ long Invocations,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Never( 
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Once( 
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Parameter( 
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ long Invocation = 1,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParameterInRange( 
            /* [in] */ BSTR Parameter,
            /* [in] */ double Minimum,
            /* [in] */ double Maximum,
            /* [defaultvalue][optional][in] */ long Invocation = 1,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParameterIsPassed( 
            /* [in] */ BSTR Parameter,
            /* [defaultvalue][optional][in] */ long Invocation = 1,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ParameterIsType( 
            /* [in] */ BSTR Parameter,
            /* [in] */ BSTR TypeName,
            /* [defaultvalue][optional][in] */ long Invocation = 1,
            /* [defaultvalue][optional][in] */ BSTR Message = (BSTR)L"") = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVerifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVerify * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVerify * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVerify * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVerify * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVerify * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVerify * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVerify * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AtLeast )( 
            IVerify * This,
            /* [in] */ long Invocations,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AtLeastOnce )( 
            IVerify * This,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AtMost )( 
            IVerify * This,
            /* [in] */ long Invocations,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AtMostOnce )( 
            IVerify * This,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Between )( 
            IVerify * This,
            /* [in] */ long Minimum,
            /* [in] */ long Maximum,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exactly )( 
            IVerify * This,
            /* [in] */ long Invocations,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Never )( 
            IVerify * This,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Once )( 
            IVerify * This,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Parameter )( 
            IVerify * This,
            /* [in] */ BSTR Parameter,
            /* [in] */ VARIANT Value,
            /* [defaultvalue][optional][in] */ long Invocation,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParameterInRange )( 
            IVerify * This,
            /* [in] */ BSTR Parameter,
            /* [in] */ double Minimum,
            /* [in] */ double Maximum,
            /* [defaultvalue][optional][in] */ long Invocation,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParameterIsPassed )( 
            IVerify * This,
            /* [in] */ BSTR Parameter,
            /* [defaultvalue][optional][in] */ long Invocation,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ParameterIsType )( 
            IVerify * This,
            /* [in] */ BSTR Parameter,
            /* [in] */ BSTR TypeName,
            /* [defaultvalue][optional][in] */ long Invocation,
            /* [defaultvalue][optional][in] */ BSTR Message);
        
        END_INTERFACE
    } IVerifyVtbl;

    interface IVerify
    {
        CONST_VTBL struct IVerifyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVerify_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVerify_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVerify_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVerify_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IVerify_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IVerify_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IVerify_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IVerify_AtLeast(This,Invocations,Message)	\
    ( (This)->lpVtbl -> AtLeast(This,Invocations,Message) ) 

#define IVerify_AtLeastOnce(This,Message)	\
    ( (This)->lpVtbl -> AtLeastOnce(This,Message) ) 

#define IVerify_AtMost(This,Invocations,Message)	\
    ( (This)->lpVtbl -> AtMost(This,Invocations,Message) ) 

#define IVerify_AtMostOnce(This,Message)	\
    ( (This)->lpVtbl -> AtMostOnce(This,Message) ) 

#define IVerify_Between(This,Minimum,Maximum,Message)	\
    ( (This)->lpVtbl -> Between(This,Minimum,Maximum,Message) ) 

#define IVerify_Exactly(This,Invocations,Message)	\
    ( (This)->lpVtbl -> Exactly(This,Invocations,Message) ) 

#define IVerify_Never(This,Message)	\
    ( (This)->lpVtbl -> Never(This,Message) ) 

#define IVerify_Once(This,Message)	\
    ( (This)->lpVtbl -> Once(This,Message) ) 

#define IVerify_Parameter(This,Parameter,Value,Invocation,Message)	\
    ( (This)->lpVtbl -> Parameter(This,Parameter,Value,Invocation,Message) ) 

#define IVerify_ParameterInRange(This,Parameter,Minimum,Maximum,Invocation,Message)	\
    ( (This)->lpVtbl -> ParameterInRange(This,Parameter,Minimum,Maximum,Invocation,Message) ) 

#define IVerify_ParameterIsPassed(This,Parameter,Invocation,Message)	\
    ( (This)->lpVtbl -> ParameterIsPassed(This,Parameter,Invocation,Message) ) 

#define IVerify_ParameterIsType(This,Parameter,TypeName,Invocation,Message)	\
    ( (This)->lpVtbl -> ParameterIsType(This,Parameter,TypeName,Invocation,Message) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVerify_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID__Extension;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f697-43f0-3b33-b105-9b8188a6f040")
_Extension;
#endif

EXTERN_C const CLSID CLSID__DockableWindowHost;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f699-43f0-3b33-b105-9b8188a6f040")
_DockableWindowHost;
#endif

EXTERN_C const CLSID CLSID_AssertClass;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f7da-43f0-3b33-b105-9b8188a6f040")
AssertClass;
#endif

EXTERN_C const CLSID CLSID_FakesProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f7dd-43f0-3b33-b105-9b8188a6f040")
FakesProvider;
#endif

EXTERN_C const CLSID CLSID_PermissiveAssertClass;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f7dc-43f0-3b33-b105-9b8188a6f040")
PermissiveAssertClass;
#endif
#endif /* __Rubberduck_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


