// Fill out your copyright notice in the Description page of Project Settings.

#include "BigPeg.h"


// Sets default values
ABigPeg::ABigPeg()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BigPegBase"));
	}

	BigPegSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BigPegSprite"));
	BigPegSprite->SetSpriteColor(FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));
	BigPegSprite->AttachTo(RootComponent);

	// Binds the BigPegOnClickFunction delegate to OnClicked
	FScriptDelegate OnClickDelegate;
	OnClickDelegate.BindUFunction(this, FName("BigPegOnClickFunction"));
	OnClicked.AddUnique(OnClickDelegate);
}

// Called when the game starts or when spawned
void ABigPeg::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABigPeg::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABigPeg::BigPegOnClickFunction()
{
	UE_LOG(LogTemp, Warning, TEXT("Selector should appear"))
	//BigPegSprite->SetSpriteColor(FLinearColor(255.0f, 0.0f, 0.0f));
}

/*
	Updates the color of the sprite after a new enum is set
	- Red (255, 0, 0)
	- Orange (0.863157f, 0.155926f, 0.046665f)
	- Yellow (255, 255, 0)
	- Green (0, 255, 0)
	- Blue (0, 0, 255)
	- Purple (0.199216, 0, 0.4)
	- Pink (255, 0, 127)
*/
void ABigPeg::UpdateSpriteColor()
{
	switch (BigPegColor)
	{
		case EBigPegColors::RED:
			BigPegSprite->SetSpriteColor(FLinearColor(255.0f, 0.0f, 0.0f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To RED"))
			break;
		case EBigPegColors::ORANGE:
			BigPegSprite->SetSpriteColor(FLinearColor(0.863157f, 0.155926f, 0.046665f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To ORANGE"))
			break;
		case EBigPegColors::YELLOW:
			BigPegSprite->SetSpriteColor(FLinearColor(255.0f, 255.0f, 0.0f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To YELLOW"))
			break;
		case EBigPegColors::GREEN:
			BigPegSprite->SetSpriteColor(FLinearColor(0.0f, 255.0f, 0.0f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To GREEN"))
			break;
		case EBigPegColors::BLUE:
			BigPegSprite->SetSpriteColor(FLinearColor(0.0f, 0.0f, 255.0f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To BLUE"))
			break;
		case EBigPegColors::PURPLE:
			BigPegSprite->SetSpriteColor(FLinearColor(0.199216f, 0.0f, 0.4f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To PURPLE"))
			break;
		case EBigPegColors::PINK:
			BigPegSprite->SetSpriteColor(FLinearColor(255.0f, 0.0f, 127.0f));
			UE_LOG(LogTemp, Warning, TEXT("Peg Color Set To PINK"))
			break;
		default:
			UE_LOG(LogTemp, Warning, TEXT("ABigPeg::SetPegSpriteColor -> What the heck happened?! How can one set an invalid enum?!?!?!?!"))
			break;
	}

}

TEnumAsByte<EBigPegColors> ABigPeg::GetBigPegColor()
{
	return BigPegColor;
}

void ABigPeg::SetBigPegColor(TEnumAsByte<EBigPegColors> color)
{
	BigPegColor = color;
	UpdateSpriteColor();
}

bool ABigPeg::GetPegEnabled()
{
	return isPegEnabled;
}

void ABigPeg::SetPegEnabled(bool result)
{
	isPegEnabled = result;
}