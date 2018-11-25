// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Paper2D/Classes/PaperSpriteComponent.h"
#include "LittlePeg.generated.h"

UENUM(BlueprintType)
enum ELittlePegColors
{
	LP_NONE UMETA(DisplayName = "None"),
	LP_WHITE UMETA(DisplayName = "White"),
	LP_RED UMETA(DisplayName = "Red")
};

UCLASS()
class MASTERMIND_API ALittlePeg : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALittlePeg();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetLittlePegColor(TEnumAsByte<ELittlePegColors> newColor);

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Little Peg", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<ELittlePegColors> LittlePegColor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Little Peg", meta = (AllowPrivateAccess = "true"))
	UPaperSpriteComponent* LittlePegSprite;

	void UpdateSpriteColor();
	
};
