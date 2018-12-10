

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 03:14:07 2038
 */
/* Compiler settings for Rubberduck.API.idl:
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


#ifndef __Rubberduck2EAPI_h__
#define __Rubberduck2EAPI_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IApiProvider_FWD_DEFINED__
#define __IApiProvider_FWD_DEFINED__
typedef interface IApiProvider IApiProvider;

#endif 	/* __IApiProvider_FWD_DEFINED__ */


#ifndef __IDeclaration_FWD_DEFINED__
#define __IDeclaration_FWD_DEFINED__
typedef interface IDeclaration IDeclaration;

#endif 	/* __IDeclaration_FWD_DEFINED__ */


#ifndef __IDeclarations_FWD_DEFINED__
#define __IDeclarations_FWD_DEFINED__
typedef interface IDeclarations IDeclarations;

#endif 	/* __IDeclarations_FWD_DEFINED__ */


#ifndef __IIdentifierReference_FWD_DEFINED__
#define __IIdentifierReference_FWD_DEFINED__
typedef interface IIdentifierReference IIdentifierReference;

#endif 	/* __IIdentifierReference_FWD_DEFINED__ */


#ifndef __IIdentifierReferences_FWD_DEFINED__
#define __IIdentifierReferences_FWD_DEFINED__
typedef interface IIdentifierReferences IIdentifierReferences;

#endif 	/* __IIdentifierReferences_FWD_DEFINED__ */


#ifndef __IParser_FWD_DEFINED__
#define __IParser_FWD_DEFINED__
typedef interface IParser IParser;

#endif 	/* __IParser_FWD_DEFINED__ */


#ifndef __IParserEvents_FWD_DEFINED__
#define __IParserEvents_FWD_DEFINED__
typedef interface IParserEvents IParserEvents;

#endif 	/* __IParserEvents_FWD_DEFINED__ */


#ifndef __ApiProvider_FWD_DEFINED__
#define __ApiProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class ApiProvider ApiProvider;
#else
typedef struct ApiProvider ApiProvider;
#endif /* __cplusplus */

#endif 	/* __ApiProvider_FWD_DEFINED__ */


#ifndef __Declaration_FWD_DEFINED__
#define __Declaration_FWD_DEFINED__

#ifdef __cplusplus
typedef class Declaration Declaration;
#else
typedef struct Declaration Declaration;
#endif /* __cplusplus */

#endif 	/* __Declaration_FWD_DEFINED__ */


#ifndef __Declarations_FWD_DEFINED__
#define __Declarations_FWD_DEFINED__

#ifdef __cplusplus
typedef class Declarations Declarations;
#else
typedef struct Declarations Declarations;
#endif /* __cplusplus */

#endif 	/* __Declarations_FWD_DEFINED__ */


#ifndef __IdentifierReference_FWD_DEFINED__
#define __IdentifierReference_FWD_DEFINED__

#ifdef __cplusplus
typedef class IdentifierReference IdentifierReference;
#else
typedef struct IdentifierReference IdentifierReference;
#endif /* __cplusplus */

#endif 	/* __IdentifierReference_FWD_DEFINED__ */


#ifndef __IdentifierReferences_FWD_DEFINED__
#define __IdentifierReferences_FWD_DEFINED__

#ifdef __cplusplus
typedef class IdentifierReferences IdentifierReferences;
#else
typedef struct IdentifierReferences IdentifierReferences;
#endif /* __cplusplus */

#endif 	/* __IdentifierReferences_FWD_DEFINED__ */


#ifndef __Parser_FWD_DEFINED__
#define __Parser_FWD_DEFINED__

#ifdef __cplusplus
typedef class Parser Parser;
#else
typedef struct Parser Parser;
#endif /* __cplusplus */

#endif 	/* __Parser_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_Rubberduck2EAPI_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_Rubberduck2EAPI_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_Rubberduck2EAPI_0000_0000_v0_0_s_ifspec;


#ifndef __RubberduckAPI_LIBRARY_DEFINED__
#define __RubberduckAPI_LIBRARY_DEFINED__

/* library RubberduckAPI */
/* [helpstring][custom][version][uuid] */ 














typedef /* [version][uuid] */  DECLSPEC_UUID("69e10024-43f0-3b33-b105-9b8188a6f040") 
enum Accessibility
    {
        rdPrivate	= 1,
        rdFriend	= 2,
        rdGlobal	= 5,
        rdImplicit	= 3,
        rdPublic	= 4,
        rdStatic	= 6
    } 	Accessibility;

typedef /* [version][uuid] */  DECLSPEC_UUID("69e10023-43f0-3b33-b105-9b8188a6f040") 
enum DeclarationType
    {
        rdBracketedExpression	= 134217728,
        rdClassModule	= 10,
        rdComAlias	= 268435456,
        rdConstant	= 131072,
        rdControl	= 98304,
        rdDocument	= 42,
        rdEnumeration	= 262144,
        rdEnumerationMember	= 524288,
        rdEvent	= 1048576,
        rdFunction	= 640,
        rdLibraryFunction	= 8389248,
        rdLibraryProcedure	= 16777600,
        rdLineLabel	= 33554432,
        rdMember	= 128,
        rdModule	= 2,
        rdParameter	= 16384,
        rdProceduralModule	= 6,
        rdProcedure	= 384,
        rdProject	= 1,
        rdProperty	= 1152,
        rdPropertyGet	= 3712,
        rdPropertyLet	= 5504,
        rdPropertySet	= 9600,
        rdUnresolvedMember	= 67108864,
        rdUserDefinedType	= 2097152,
        rdUserDefinedTypeMember	= 4194304,
        rdUserForm	= 26,
        rdVariable	= 32768
    } 	DeclarationType;

typedef /* [version][uuid] */  DECLSPEC_UUID("69e10025-43f0-3b33-b105-9b8188a6f040") 
enum ParserState
    {
        rdPending	= 0,
        rdStarted	= 1,
        rdLoadingReference	= 2,
        rdParsing	= 3,
        rdParsed	= 4,
        rdResolvingDeclarations	= 5,
        rdResolvedDeclarations	= 6,
        rdResolvingReferences	= 7,
        rdReady	= 8,
        rdError	= 10,
        rdResolverError	= 11,
        rdUnexpectedError	= 12
    } 	ParserState;


EXTERN_C const IID LIBID_RubberduckAPI;

#ifndef __IApiProvider_INTERFACE_DEFINED__
#define __IApiProvider_INTERFACE_DEFINED__

/* interface IApiProvider */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IApiProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f78a-43f0-3b33-b105-9b8188a6f040")
    IApiProvider : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetParser( 
            /* [in] */ VARIANT vbe,
            /* [retval][out] */ IParser **pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IApiProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IApiProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IApiProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IApiProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IApiProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IApiProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IApiProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IApiProvider * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetParser )( 
            IApiProvider * This,
            /* [in] */ VARIANT vbe,
            /* [retval][out] */ IParser **pRetVal);
        
        END_INTERFACE
    } IApiProviderVtbl;

    interface IApiProvider
    {
        CONST_VTBL struct IApiProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IApiProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IApiProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IApiProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IApiProvider_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IApiProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IApiProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IApiProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IApiProvider_GetParser(This,vbe,pRetVal)	\
    ( (This)->lpVtbl -> GetParser(This,vbe,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IApiProvider_INTERFACE_DEFINED__ */


#ifndef __IDeclaration_INTERFACE_DEFINED__
#define __IDeclaration_INTERFACE_DEFINED__

/* interface IDeclaration */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IDeclaration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f781-43f0-3b33-b105-9b8188a6f040")
    IDeclaration : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Accessibility( 
            /* [retval][out] */ Accessibility *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DeclarationType( 
            /* [retval][out] */ DeclarationType *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TypeName( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsArray( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ParentDeclaration( 
            /* [retval][out] */ IDeclaration **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_References( 
            /* [retval][out] */ IIdentifierReferences **pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDeclarationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDeclaration * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDeclaration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDeclaration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDeclaration * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDeclaration * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDeclaration * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDeclaration * This,
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
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IDeclaration * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Accessibility )( 
            IDeclaration * This,
            /* [retval][out] */ Accessibility *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_DeclarationType )( 
            IDeclaration * This,
            /* [retval][out] */ DeclarationType *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_TypeName )( 
            IDeclaration * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsArray )( 
            IDeclaration * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ParentDeclaration )( 
            IDeclaration * This,
            /* [retval][out] */ IDeclaration **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_References )( 
            IDeclaration * This,
            /* [retval][out] */ IIdentifierReferences **pRetVal);
        
        END_INTERFACE
    } IDeclarationVtbl;

    interface IDeclaration
    {
        CONST_VTBL struct IDeclarationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDeclaration_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDeclaration_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDeclaration_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDeclaration_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDeclaration_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDeclaration_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDeclaration_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDeclaration_get_Name(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Name(This,pRetVal) ) 

#define IDeclaration_get_Accessibility(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Accessibility(This,pRetVal) ) 

#define IDeclaration_get_DeclarationType(This,pRetVal)	\
    ( (This)->lpVtbl -> get_DeclarationType(This,pRetVal) ) 

#define IDeclaration_get_TypeName(This,pRetVal)	\
    ( (This)->lpVtbl -> get_TypeName(This,pRetVal) ) 

#define IDeclaration_get_IsArray(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsArray(This,pRetVal) ) 

#define IDeclaration_get_ParentDeclaration(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ParentDeclaration(This,pRetVal) ) 

#define IDeclaration_get_References(This,pRetVal)	\
    ( (This)->lpVtbl -> get_References(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDeclaration_INTERFACE_DEFINED__ */


#ifndef __IDeclarations_INTERFACE_DEFINED__
#define __IDeclarations_INTERFACE_DEFINED__

/* interface IDeclarations */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IDeclarations;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f788-43f0-3b33-b105-9b8188a6f040")
    IDeclarations : public IDispatch
    {
    public:
        virtual /* [custom][propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IDeclaration **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE _GetEnumerator( 
            /* [retval][out] */ IEnumVARIANT **pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDeclarationsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDeclarations * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDeclarations * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDeclarations * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDeclarations * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDeclarations * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDeclarations * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDeclarations * This,
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
        
        /* [custom][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IDeclarations * This,
            /* [in] */ long Index,
            /* [retval][out] */ IDeclaration **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IDeclarations * This,
            /* [retval][out] */ long *pRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *_GetEnumerator )( 
            IDeclarations * This,
            /* [retval][out] */ IEnumVARIANT **pRetVal);
        
        END_INTERFACE
    } IDeclarationsVtbl;

    interface IDeclarations
    {
        CONST_VTBL struct IDeclarationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDeclarations_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDeclarations_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDeclarations_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDeclarations_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDeclarations_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDeclarations_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDeclarations_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDeclarations_get_Item(This,Index,pRetVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pRetVal) ) 

#define IDeclarations_get_Count(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Count(This,pRetVal) ) 

#define IDeclarations__GetEnumerator(This,pRetVal)	\
    ( (This)->lpVtbl -> _GetEnumerator(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDeclarations_INTERFACE_DEFINED__ */


#ifndef __IIdentifierReference_INTERFACE_DEFINED__
#define __IIdentifierReference_INTERFACE_DEFINED__

/* interface IIdentifierReference */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IIdentifierReference;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f783-43f0-3b33-b105-9b8188a6f040")
    IIdentifierReference : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Declaration( 
            /* [retval][out] */ IDeclaration **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ParentScope( 
            /* [retval][out] */ IDeclaration **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ParentNonScoping( 
            /* [retval][out] */ IDeclaration **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsAssignment( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_StartLine( 
            /* [retval][out] */ long *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_StartColumn( 
            /* [retval][out] */ long *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EndLine( 
            /* [retval][out] */ long *pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EndColumn( 
            /* [retval][out] */ long *pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIdentifierReferenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIdentifierReference * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIdentifierReference * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIdentifierReference * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIdentifierReference * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIdentifierReference * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIdentifierReference * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIdentifierReference * This,
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
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Declaration )( 
            IIdentifierReference * This,
            /* [retval][out] */ IDeclaration **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ParentScope )( 
            IIdentifierReference * This,
            /* [retval][out] */ IDeclaration **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_ParentNonScoping )( 
            IIdentifierReference * This,
            /* [retval][out] */ IDeclaration **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_IsAssignment )( 
            IIdentifierReference * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StartLine )( 
            IIdentifierReference * This,
            /* [retval][out] */ long *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StartColumn )( 
            IIdentifierReference * This,
            /* [retval][out] */ long *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndLine )( 
            IIdentifierReference * This,
            /* [retval][out] */ long *pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_EndColumn )( 
            IIdentifierReference * This,
            /* [retval][out] */ long *pRetVal);
        
        END_INTERFACE
    } IIdentifierReferenceVtbl;

    interface IIdentifierReference
    {
        CONST_VTBL struct IIdentifierReferenceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIdentifierReference_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIdentifierReference_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIdentifierReference_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIdentifierReference_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIdentifierReference_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIdentifierReference_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIdentifierReference_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIdentifierReference_get_Declaration(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Declaration(This,pRetVal) ) 

#define IIdentifierReference_get_ParentScope(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ParentScope(This,pRetVal) ) 

#define IIdentifierReference_get_ParentNonScoping(This,pRetVal)	\
    ( (This)->lpVtbl -> get_ParentNonScoping(This,pRetVal) ) 

#define IIdentifierReference_get_IsAssignment(This,pRetVal)	\
    ( (This)->lpVtbl -> get_IsAssignment(This,pRetVal) ) 

#define IIdentifierReference_get_StartLine(This,pRetVal)	\
    ( (This)->lpVtbl -> get_StartLine(This,pRetVal) ) 

#define IIdentifierReference_get_StartColumn(This,pRetVal)	\
    ( (This)->lpVtbl -> get_StartColumn(This,pRetVal) ) 

#define IIdentifierReference_get_EndLine(This,pRetVal)	\
    ( (This)->lpVtbl -> get_EndLine(This,pRetVal) ) 

#define IIdentifierReference_get_EndColumn(This,pRetVal)	\
    ( (This)->lpVtbl -> get_EndColumn(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIdentifierReference_INTERFACE_DEFINED__ */


#ifndef __IIdentifierReferences_INTERFACE_DEFINED__
#define __IIdentifierReferences_INTERFACE_DEFINED__

/* interface IIdentifierReferences */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IIdentifierReferences;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f78c-43f0-3b33-b105-9b8188a6f040")
    IIdentifierReferences : public IDispatch
    {
    public:
        virtual /* [custom][propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IIdentifierReference **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pRetVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE _GetEnumerator( 
            /* [retval][out] */ IEnumVARIANT **pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IIdentifierReferencesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IIdentifierReferences * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IIdentifierReferences * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IIdentifierReferences * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IIdentifierReferences * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IIdentifierReferences * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IIdentifierReferences * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IIdentifierReferences * This,
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
        
        /* [custom][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IIdentifierReferences * This,
            /* [in] */ long Index,
            /* [retval][out] */ IIdentifierReference **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IIdentifierReferences * This,
            /* [retval][out] */ long *pRetVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *_GetEnumerator )( 
            IIdentifierReferences * This,
            /* [retval][out] */ IEnumVARIANT **pRetVal);
        
        END_INTERFACE
    } IIdentifierReferencesVtbl;

    interface IIdentifierReferences
    {
        CONST_VTBL struct IIdentifierReferencesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIdentifierReferences_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IIdentifierReferences_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IIdentifierReferences_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IIdentifierReferences_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IIdentifierReferences_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IIdentifierReferences_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IIdentifierReferences_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IIdentifierReferences_get_Item(This,Index,pRetVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pRetVal) ) 

#define IIdentifierReferences_get_Count(This,pRetVal)	\
    ( (This)->lpVtbl -> get_Count(This,pRetVal) ) 

#define IIdentifierReferences__GetEnumerator(This,pRetVal)	\
    ( (This)->lpVtbl -> _GetEnumerator(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IIdentifierReferences_INTERFACE_DEFINED__ */


#ifndef __IParser_INTERFACE_DEFINED__
#define __IParser_INTERFACE_DEFINED__

/* interface IParser */
/* [object][oleautomation][dual][custom][version][uuid] */ 


EXTERN_C const IID IID_IParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("69e0f785-43f0-3b33-b105-9b8188a6f040")
    IParser : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Parse( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BeginParse( void) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AllDeclarations( 
            /* [retval][out] */ IDeclarations **pRetVal) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_UserDeclarations( 
            /* [retval][out] */ IDeclarations **pRetVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IParser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IParser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IParser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IParser * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Parse )( 
            IParser * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BeginParse )( 
            IParser * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_AllDeclarations )( 
            IParser * This,
            /* [retval][out] */ IDeclarations **pRetVal);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_UserDeclarations )( 
            IParser * This,
            /* [retval][out] */ IDeclarations **pRetVal);
        
        END_INTERFACE
    } IParserVtbl;

    interface IParser
    {
        CONST_VTBL struct IParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IParser_Parse(This)	\
    ( (This)->lpVtbl -> Parse(This) ) 

#define IParser_BeginParse(This)	\
    ( (This)->lpVtbl -> BeginParse(This) ) 

#define IParser_get_AllDeclarations(This,pRetVal)	\
    ( (This)->lpVtbl -> get_AllDeclarations(This,pRetVal) ) 

#define IParser_get_UserDeclarations(This,pRetVal)	\
    ( (This)->lpVtbl -> get_UserDeclarations(This,pRetVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IParser_INTERFACE_DEFINED__ */


#ifndef __IParserEvents_DISPINTERFACE_DEFINED__
#define __IParserEvents_DISPINTERFACE_DEFINED__

/* dispinterface IParserEvents */
/* [custom][version][uuid] */ 


EXTERN_C const IID DIID_IParserEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("69e0f787-43f0-3b33-b105-9b8188a6f040")
    IParserEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IParserEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IParserEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IParserEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IParserEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IParserEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IParserEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IParserEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IParserEvents * This,
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
        
        END_INTERFACE
    } IParserEventsVtbl;

    interface IParserEvents
    {
        CONST_VTBL struct IParserEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParserEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IParserEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IParserEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IParserEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IParserEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IParserEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IParserEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IParserEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ApiProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f78b-43f0-3b33-b105-9b8188a6f040")
ApiProvider;
#endif

EXTERN_C const CLSID CLSID_Declaration;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f782-43f0-3b33-b105-9b8188a6f040")
Declaration;
#endif

EXTERN_C const CLSID CLSID_Declarations;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f789-43f0-3b33-b105-9b8188a6f040")
Declarations;
#endif

EXTERN_C const CLSID CLSID_IdentifierReference;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f784-43f0-3b33-b105-9b8188a6f040")
IdentifierReference;
#endif

EXTERN_C const CLSID CLSID_IdentifierReferences;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f78d-43f0-3b33-b105-9b8188a6f040")
IdentifierReferences;
#endif

EXTERN_C const CLSID CLSID_Parser;

#ifdef __cplusplus

class DECLSPEC_UUID("69e0f786-43f0-3b33-b105-9b8188a6f040")
Parser;
#endif
#endif /* __RubberduckAPI_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


