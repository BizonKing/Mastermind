// Fill out your copyright notice in the Description page of Project Settings.

/*
	A BigPeg needs
	- SpriteComponent to give visual
	- A color
	- Enum of the different types of colors the Big Peg can be
	- 
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "Engine/Classes/GameFramework/PlayerInput.h"
#include "BigPeg.generated.h"

/*
	- Red (255, 0, 0)
	- Orange (255, 128, 0)
	- Yellow (255, 255, 0)
	- Green (0, 255, 0)
	- Blue (0, 0, 255)
	- Purple (0.199216, 0, 0.4)
	- Pink (255, 0, 127)
*/
UENUM(BlueprintType)
enum EBigPegColors
{
	NONE UMETA(DisplayName = "None"),
	RED UMETA(DisplayName = "Red"),
	ORANGE UMETA(DisplayName = "Orange"),
	YELLOW UMETA(DisplayName = "Yellow"),
	GREEN UMETA(DisplayName = "Green"),
	BLUE UMETA(DisplayName = "Blue"),
	PURPLE UMETA(DisplayName = "Purple"),
	PINK UMETA(DisplayName = "Pink")
};

UCLASS()
class MASTERMIND_API ABigPeg : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABigPeg();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Gets the color of a Big Peg
	UFUNCTION(BlueprintCallable)
	TEnumAsByte<EBigPegColors> GetBigPegColor();
	// Sets the color of a Big Peg
	UFUNCTION(BlueprintCallable)
	void SetBigPegColor(TEnumAsByte<EBigPegColors> color);

	// Sees if peg is enabled for interaction
	UFUNCTION(BlueprintCallable)
	bool GetPegEnabled();
	// Sets whether peg is enabled or disabled for interaction
	UFUNCTION(BlueprintCallable)
	void SetPegEnabled(bool result);


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Big Peg", meta = (AllowPrivateAccess = "true"))
	UPaperSpriteComponent* BigPegSprite;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Big Peg", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EBigPegColors> BigPegColor;

	// Board will enable and disable pegs when checking and stuff;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Big Peg", meta = (AllowPrivateAccess = "true"))
	bool isPegEnabled = true;

	// Function called whenever the Big Peg is clicked on
	void BigPegOnClickFunction();
	// Updates Sprite Color
	void UpdateSpriteColor();
	
};
