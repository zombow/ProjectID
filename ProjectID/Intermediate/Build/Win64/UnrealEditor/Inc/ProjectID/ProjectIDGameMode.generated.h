// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROJECTID_ProjectIDGameMode_generated_h
#error "ProjectIDGameMode.generated.h already included, missing '#pragma once' in ProjectIDGameMode.h"
#endif
#define PROJECTID_ProjectIDGameMode_generated_h

#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_SPARSE_DATA
#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_RPC_WRAPPERS
#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectIDGameMode(); \
	friend struct Z_Construct_UClass_AProjectIDGameMode_Statics; \
public: \
	DECLARE_CLASS(AProjectIDGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectID"), PROJECTID_API) \
	DECLARE_SERIALIZER(AProjectIDGameMode)


#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAProjectIDGameMode(); \
	friend struct Z_Construct_UClass_AProjectIDGameMode_Statics; \
public: \
	DECLARE_CLASS(AProjectIDGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectID"), PROJECTID_API) \
	DECLARE_SERIALIZER(AProjectIDGameMode)


#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	PROJECTID_API AProjectIDGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectIDGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PROJECTID_API, AProjectIDGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectIDGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	PROJECTID_API AProjectIDGameMode(AProjectIDGameMode&&); \
	PROJECTID_API AProjectIDGameMode(const AProjectIDGameMode&); \
public:


#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	PROJECTID_API AProjectIDGameMode(AProjectIDGameMode&&); \
	PROJECTID_API AProjectIDGameMode(const AProjectIDGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(PROJECTID_API, AProjectIDGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectIDGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectIDGameMode)


#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_9_PROLOG
#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_SPARSE_DATA \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_RPC_WRAPPERS \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_INCLASS \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_SPARSE_DATA \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTID_API UClass* StaticClass<class AProjectIDGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectID_Source_ProjectID_ProjectIDGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
