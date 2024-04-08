// Copyright Necther Louie Dev


#include "Character/AuraEnemy.h"
#include "AuraTemplate/AuraTemplate.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemy::HighlightActor()
{
	bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(bHighlighted);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(bHighlighted);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnhighlightActor()
{
	bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(bHighlighted);
	GetMesh()->SetCustomDepthStencilValue(0);

	Weapon->SetRenderCustomDepth(bHighlighted);
	Weapon->SetCustomDepthStencilValue(0);
}
