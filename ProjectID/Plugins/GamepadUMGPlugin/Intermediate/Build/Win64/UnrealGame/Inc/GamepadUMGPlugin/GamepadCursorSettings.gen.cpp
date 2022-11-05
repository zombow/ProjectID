// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GamepadUMGPlugin/Public/GamepadCursorSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGamepadCursorSettings() {}
// Cross Module References
	GAMEPADUMGPLUGIN_API UClass* Z_Construct_UClass_UGamepadCursorSettings_NoRegister();
	GAMEPADUMGPLUGIN_API UClass* Z_Construct_UClass_UGamepadCursorSettings();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	UPackage* Z_Construct_UPackage__Script_GamepadUMGPlugin();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
// End Cross Module References
	void UGamepadCursorSettings::StaticRegisterNativesUGamepadCursorSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGamepadCursorSettings);
	UClass* Z_Construct_UClass_UGamepadCursorSettings_NoRegister()
	{
		return UGamepadCursorSettings::StaticClass();
	}
	struct Z_Construct_UClass_UGamepadCursorSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnalogCursorAccelerationCurve_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AnalogCursorAccelerationCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxAnalogCursorSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAnalogCursorSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxAnalogCursorSpeedWhenHovered_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAnalogCursorSpeedWhenHovered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnalogCursorDragCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AnalogCursorDragCoefficient;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnalogCursorDragCoefficientWhenHovered_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AnalogCursorDragCoefficientWhenHovered;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinAnalogCursorSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinAnalogCursorSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnalogCursorDeadZone_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AnalogCursorDeadZone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnalogCursorAccelerationMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AnalogCursorAccelerationMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnalogCursorSize_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AnalogCursorSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseEngineAnalogCursor_MetaData[];
#endif
		static void NewProp_bUseEngineAnalogCursor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseEngineAnalogCursor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAnalogCursorNoAcceleration_MetaData[];
#endif
		static void NewProp_bAnalogCursorNoAcceleration_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAnalogCursorNoAcceleration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGamepadCursorSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_GamepadUMGPlugin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *  These settings are used with the Gamepad UMG Plugin!\n *\n *  Epic Developer Nick Darnell wrote this Gamepad-friendly UMG code!\n *\n *  I simply compiled the code into a plugin :) \n *\n *  <3 Rama\n */" },
		{ "IncludePath", "GamepadCursorSettings.h" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "These settings are used with the Gamepad UMG Plugin!\n\nEpic Developer Nick Darnell wrote this Gamepad-friendly UMG code!\n\nI simply compiled the code into a plugin :)\n\n<3 Rama" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationCurve_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "XAxisName", "Strength" },
		{ "YAxisName", "Acceleration" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationCurve = { "AnalogCursorAccelerationCurve", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, AnalogCursorAccelerationCurve), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationCurve_MetaData)) }; // 1196190759
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeed_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMin", "1.0" },
		{ "Comment", "/** The max speed of the Analog Cursor */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "The max speed of the Analog Cursor" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeed = { "MaxAnalogCursorSpeed", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, MaxAnalogCursorSpeed), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeedWhenHovered_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMin", "1.0" },
		{ "Comment", "/** The max speed of the Analog Cursor when hovering over a widget that is interactable */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "The max speed of the Analog Cursor when hovering over a widget that is interactable" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeedWhenHovered = { "MaxAnalogCursorSpeedWhenHovered", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, MaxAnalogCursorSpeedWhenHovered), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeedWhenHovered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeedWhenHovered_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficient_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** The coefficient of drag applied to the cursor */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "The coefficient of drag applied to the cursor" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficient = { "AnalogCursorDragCoefficient", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, AnalogCursorDragCoefficient), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficient_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficient_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficientWhenHovered_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** The coefficient of drag applied to the cursor when hovering */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "The coefficient of drag applied to the cursor when hovering" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficientWhenHovered = { "AnalogCursorDragCoefficientWhenHovered", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, AnalogCursorDragCoefficientWhenHovered), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficientWhenHovered_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficientWhenHovered_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MinAnalogCursorSpeed_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** The min speed of the analog cursor. If it goes below this value, the speed is set to 0. */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "The min speed of the analog cursor. If it goes below this value, the speed is set to 0." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MinAnalogCursorSpeed = { "MinAnalogCursorSpeed", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, MinAnalogCursorSpeed), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MinAnalogCursorSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MinAnalogCursorSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDeadZone_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "Comment", "/** Deadzone value for input from the analog stick */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "Deadzone value for input from the analog stick" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDeadZone = { "AnalogCursorDeadZone", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, AnalogCursorDeadZone), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDeadZone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDeadZone_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationMultiplier_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMin", "1.0" },
		{ "Comment", "/** Multiplied by the value spit out by the normalized acceleration curve */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "Multiplied by the value spit out by the normalized acceleration curve" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationMultiplier = { "AnalogCursorAccelerationMultiplier", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, AnalogCursorAccelerationMultiplier), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationMultiplier_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationMultiplier_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorSize_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "ClampMax", "128.0" },
		{ "ClampMin", "1.0" },
		{ "Comment", "/** The size (on screen) of the analog cursor */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "The size (on screen) of the analog cursor" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorSize = { "AnalogCursorSize", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGamepadCursorSettings, AnalogCursorSize), METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "Comment", "/** If true, defaults to the Engine's Analog Cursor */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "If true, defaults to the Engine's Analog Cursor" },
	};
#endif
	void Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor_SetBit(void* Obj)
	{
		((UGamepadCursorSettings*)Obj)->bUseEngineAnalogCursor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor = { "bUseEngineAnalogCursor", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGamepadCursorSettings), &Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration_MetaData[] = {
		{ "Category", "Analog Cursor" },
		{ "Comment", "/** If True, AnalogCursorAccelerationCurve will be used as a Velocity Curve */" },
		{ "ModuleRelativePath", "Public/GamepadCursorSettings.h" },
		{ "ToolTip", "If True, AnalogCursorAccelerationCurve will be used as a Velocity Curve" },
	};
#endif
	void Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration_SetBit(void* Obj)
	{
		((UGamepadCursorSettings*)Obj)->bAnalogCursorNoAcceleration = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration = { "bAnalogCursorNoAcceleration", nullptr, (EPropertyFlags)0x0040000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UGamepadCursorSettings), &Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration_SetBit, METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGamepadCursorSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MaxAnalogCursorSpeedWhenHovered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficient,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDragCoefficientWhenHovered,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_MinAnalogCursorSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorDeadZone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorAccelerationMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_AnalogCursorSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bUseEngineAnalogCursor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGamepadCursorSettings_Statics::NewProp_bAnalogCursorNoAcceleration,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGamepadCursorSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGamepadCursorSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGamepadCursorSettings_Statics::ClassParams = {
		&UGamepadCursorSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGamepadCursorSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UGamepadCursorSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGamepadCursorSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGamepadCursorSettings()
	{
		if (!Z_Registration_Info_UClass_UGamepadCursorSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGamepadCursorSettings.OuterSingleton, Z_Construct_UClass_UGamepadCursorSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGamepadCursorSettings.OuterSingleton;
	}
	template<> GAMEPADUMGPLUGIN_API UClass* StaticClass<UGamepadCursorSettings>()
	{
		return UGamepadCursorSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGamepadCursorSettings);
	struct Z_CompiledInDeferFile_FID_ProjectID_Plugins_GamepadUMGPlugin_Source_GamepadUMGPlugin_Public_GamepadCursorSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectID_Plugins_GamepadUMGPlugin_Source_GamepadUMGPlugin_Public_GamepadCursorSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGamepadCursorSettings, UGamepadCursorSettings::StaticClass, TEXT("UGamepadCursorSettings"), &Z_Registration_Info_UClass_UGamepadCursorSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGamepadCursorSettings), 3572249838U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ProjectID_Plugins_GamepadUMGPlugin_Source_GamepadUMGPlugin_Public_GamepadCursorSettings_h_2736784060(TEXT("/Script/GamepadUMGPlugin"),
		Z_CompiledInDeferFile_FID_ProjectID_Plugins_GamepadUMGPlugin_Source_GamepadUMGPlugin_Public_GamepadCursorSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ProjectID_Plugins_GamepadUMGPlugin_Source_GamepadUMGPlugin_Public_GamepadCursorSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
