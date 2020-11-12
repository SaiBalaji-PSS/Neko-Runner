// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Neko.generated.h"

/**
 * 
 */
UCLASS()
class NEKORUN_API ANeko : public APaperCharacter
{
	GENERATED_BODY()
    

public:
	ANeko();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
		bool IsPlayerDead;

protected:
	// This function is from ACharacter class which is the parent of this class Parent
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	
	void SlideDown();

	AActor* Player;

	void SlideUp();



};
