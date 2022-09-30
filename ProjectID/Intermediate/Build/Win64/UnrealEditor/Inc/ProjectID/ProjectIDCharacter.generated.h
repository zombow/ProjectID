// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTID_ProjectIDCharacter_generated_h
#error "ProjectIDCharacter.generated.h already included, missing '#pragma once' in ProjectIDCharacter.h"
#endif
#define PROJECTID_ProjectIDCharacter_generated_h

#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_18_DELEGATE \
static inline void FOnUseItem_DelegateWrapper(const FMulticastScriptDelegate& OnUseItem) \
{ \
	OnUseItem.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_SPARSE_DATA
#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_RPC_WRAPPERS
#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectIDCharacter(); \
	friend struct Z_Construct_UClass_AProjectIDCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectIDCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectID"), NO_API) \
	DECLARE_SERIALIZER(AProjectIDCharacter)


#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAProjectIDCharacter(); \
	friend struct Z_Construct_UClass_AProjectIDCharacter_Statics; \
public: \
	DECLARE_CLASS(AProjectIDCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectID"), NO_API) \
	DECLARE_SERIALIZER(AProjectIDCharacter)


#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectIDCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectIDCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectIDCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectIDCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectIDCharacter(AProjectIDCharacter&&); \
	NO_API AProjectIDCharacter(const AProjectIDCharacter&); \
public:


#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectIDCharacter(AProjectIDCharacter&&); \
	NO_API AProjectIDCharacter(const AProjectIDCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectIDCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectIDCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectIDCharacter)


#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_20_PROLOG
#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_SPARSE_DATA \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_RPC_WRAPPERS \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_INCLASS \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_SPARSE_DATA \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_INCLASS_NO_PURE_DECLS \
	FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTID_API UClass* StaticClass<class AProjectIDCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectID_Source_ProjectID_ProjectIDCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
