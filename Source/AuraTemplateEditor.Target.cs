// Copyright Necther Louie Dev

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraTemplateEditorTarget : TargetRules
{
	public AuraTemplateEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "AuraTemplate" } );
	}
}
