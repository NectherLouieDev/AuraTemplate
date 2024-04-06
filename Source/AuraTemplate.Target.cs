// Copyright Necther Louie Dev

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraTemplateTarget : TargetRules
{
	public AuraTemplateTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "AuraTemplate" } );
	}
}
