// Fill out your copyright notice in the Description page of Project Settings.


#include "Neko.h"

#include "Kismet/GameplayStatics.h"



ANeko::ANeko()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ANeko::BeginPlay()
{
	Super::BeginPlay();

	Player = UGameplayStatics::GetPlayerPawn(this,0);

	IsPlayerDead = false;


}

void ANeko::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}






void ANeko::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*This input binding calls in-built Jump and Stop Jump function of the character class*/
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Slide", IE_Pressed, this, &ANeko::SlideDown);
	PlayerInputComponent->BindAction("Slide", IE_Released, this, &ANeko::SlideUp);

	

}

void ANeko::SlideDown()
{
	Crouch();


	

}
void ANeko::SlideUp()
{
	UnCrouch();


	
	

}
