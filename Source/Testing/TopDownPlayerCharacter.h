#pragma once


#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "TopDownPlayerCharacter.generated.h"

class UTestingAttributeSet;
class UGameplayAbility;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMaxSpeedChanged, float, NewValue, float, OldValue);

UCLASS()
class ATopDownPlayerCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    ATopDownPlayerCharacter(const FObjectInitializer& ObjInit);

    virtual void BeginPlay() override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UTestingAttributeSet* AttributeSet;

    UFUNCTION(BlueprintCallable)
    void InitializeAttributeSet();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
    FDelegateHandle MaxSpeedChangedDelegate;

    UPROPERTY(BlueprintAssignable)
	FOnMaxSpeedChanged OnMaxSpeedChanged;

    virtual void MaxSpeedChanged(const FOnAttributeChangeData& Data);

private:

    void OnMoveForward(float Amount);
    void OnMoveRight(float Amount);
};