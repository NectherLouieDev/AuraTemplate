// Copyright Necther Louie Dev

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
* BOILERPLATE
* - Declaration
* 
* UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_<ATTR_NAME>, Category = "<ATTR_CAT")
* FGameplayAttributeData <ATTR_NAME>;
* 
* UFUNCTION()
* void OnRep_<ATTR_NAME>(const FGameplayAttributeData& Old<ATTR_NAME>) const;
* 
* ATTRIBUTE_ACCESSORS(UAuraAttributeSet, <ATTR_NAME>);
* 
* 
* - Definition
* 
* Inside GetLifetimeReplicatedProps();
* DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, <ATTR_NAME>, COND_None, REPNOTIFY_Always);
* 
* Inside OnRep_<ATTR_NAME>();
* GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, <ATTR_NAME>, Old<ATTR_NAME>);
*/
UCLASS()
class AURATEMPLATE_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
