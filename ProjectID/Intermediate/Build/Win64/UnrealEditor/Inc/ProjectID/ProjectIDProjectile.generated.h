// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef PROJECTID_ProjectIDProjectile_generated_h
#error "ProjectIDProjectile.generated.h already included, missing '#pragma once' in ProjectIDProjectile.h"
#endif
#define PROJECTID_ProjectIDProjectile_generated_h

#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_SPARSE_DATA
#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectIDProjectile(); \
	friend struct Z_Construct_UClass_AProjectIDProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectIDProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectID"), NO_API) \
	DECLARE_SERIALIZER(AProjectIDProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAProjectIDProjectile(); \
	friend struct Z_Construct_UClass_AProjectIDProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectIDProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProjectID"), NO_API) \
	DECLARE_SERIALIZER(AProjectIDProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectIDProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectIDProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectIDProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectIDProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectIDProjectile(AProjectIDProjectile&&); \
	NO_API AProjectIDProjectile(const AProjectIDProjectile&); \
public:


#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectIDProjectile(AProjectIDProjectile&&); \
	NO_API AProjectIDProjectile(const AProjectIDProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectIDProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectIDProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectIDProjectile)


#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_12_PROLOG
#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_SPARSE_DATA \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_RPC_WRAPPERS \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_INCLASS \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_SPARSE_DATA \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROJECTID_API UClass* StaticClass<class AProjectIDProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ProjectID_Source_ProjectID_ProjectIDProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
