// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectID_init() {}
	PROJECTID_API UFunction* Z_Construct_UDelegateFunction_ProjectID_OnPickUp__DelegateSignature();
	PROJECTID_API UFunction* Z_Construct_UDelegateFunction_ProjectID_OnUseItem__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectID;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectID()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectID.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectID_OnPickUp__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ProjectID_OnUseItem__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectID",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x07F35A48,
				0xB25D8217,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectID.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectID.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectID(Z_Construct_UPackage__Script_ProjectID, TEXT("/Script/ProjectID"), Z_Registration_Info_UPackage__Script_ProjectID, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x07F35A48, 0xB25D8217));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
