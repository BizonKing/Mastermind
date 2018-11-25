// Fill out your copyright notice in the Description page of Project Settings.

#include "Board.h"
#include "Kismet/GameplayStatics.h"
#include <time.h>

void DisableRow(TArray<ABigPeg*> row);
void EnableRow(TArray<ABigPeg*> row);

// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BoardBase"));
	}

	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("BoardSprite"));
	SpriteComponent->AttachTo(RootComponent);
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	
	// Seeds the random number generator
	FMath::SRandInit(FDateTime::Now().GetTicks());

	// Creates the code the player needs to find
	for (int i = 1; i <= 4; ++i)
	{
		int temp = FMath::Rand() % 7 + 1;
		switch (temp)
		{
		case 1: // Red
			SecretCode.Add(EBigPegColors::RED);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> RED"))
				break;
		case 2: // Orange
			SecretCode.Add(EBigPegColors::ORANGE);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> ORANGE"))
				break;
		case 3: // Yellow
			SecretCode.Add(EBigPegColors::YELLOW);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> YELLOW"))
				break;
		case 4: // Green
			SecretCode.Add(EBigPegColors::GREEN);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> GREEN"))
				break;
		case 5: // Blue
			SecretCode.Add(EBigPegColors::BLUE);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> BLUE"))
				break;
		case 6: // Purple
			SecretCode.Add(EBigPegColors::PURPLE);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> PURPLE"))
				break;
		case 7: // Pink
			SecretCode.Add(EBigPegColors::PINK);
			UE_LOG(LogTemp, Warning, TEXT("Secret Code Color -> PINK"))
				break;
		default:
			break;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Size of Secret Code Array %d"), SecretCode.Num())
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
	GUIDE ON GIVING FEEDBACK
	- White peg means one peg is correct, but in the wrong place
	- Red peg means that one peg is correct, AND is in the right hole
	- Order of feedback pegs does not matter (but may put them in order to make things easier)

*/
void ABoard::CheckAndGiveFeedBack()
{
	bool slotCorrect[] = {false, false, false, false};
	TArray<ABigPeg*> rowOfPegs;
	TArray<ABigPeg*> nextRowOfPegs;
	TArray<ALittlePeg*> rowOfLittlePegs;

	// Sets up our row of pegs and little pegs
	switch (currRow)
	{
	case 1:
		rowOfPegs = bigPegRow1;
		nextRowOfPegs = bigPegRow2;
		rowOfLittlePegs = littlePegRow1;
		break;
	case 2:
		rowOfPegs = bigPegRow2;
		nextRowOfPegs = bigPegRow3;
		rowOfLittlePegs = littlePegRow2;
		break;
	case 3:
		rowOfPegs = bigPegRow3;
		nextRowOfPegs = bigPegRow4;
		rowOfLittlePegs = littlePegRow3;
		break;
	case 4:
		rowOfPegs = bigPegRow4;
		nextRowOfPegs = bigPegRow5;
		rowOfLittlePegs = littlePegRow4;
		break;
	case 5:
		rowOfPegs = bigPegRow5;
		nextRowOfPegs = bigPegRow6;
		rowOfLittlePegs = littlePegRow5;
		break;
	case 6:
		rowOfPegs = bigPegRow6;
		nextRowOfPegs = bigPegRow7;
		rowOfLittlePegs = littlePegRow6;
		break;
	case 7:
		rowOfPegs = bigPegRow7;
		nextRowOfPegs = bigPegRow8;
		rowOfLittlePegs = littlePegRow7;
		break;
	case 8:
		rowOfPegs = bigPegRow8;
		nextRowOfPegs = bigPegRow9;
		rowOfLittlePegs = littlePegRow8;
		break;
	case 9:
		rowOfPegs = bigPegRow9;
		nextRowOfPegs = bigPegRow10;
		rowOfLittlePegs = littlePegRow9;
		break;
	case 10:
		rowOfPegs = bigPegRow10;
		nextRowOfPegs = bigPegRow11;
		rowOfLittlePegs = littlePegRow10;
		break;
	case 11:
		rowOfPegs = bigPegRow11;
		nextRowOfPegs = bigPegRow12;
		rowOfLittlePegs = littlePegRow11;
		break;
	case 12:
		rowOfPegs = bigPegRow12;
		rowOfLittlePegs = littlePegRow12;
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("ABoard::CheckAndGiveFeedback() Error in currRow switch"))
		break;
	}

	// First check for correct pegs
	for (int i = 0; i < 4; ++i)
	{
		if (rowOfPegs[i]->GetBigPegColor().GetValue() == EBigPegColors::NONE)
		{
			// Can't continue because one peg is missing
			UE_LOG(LogTemp, Error, TEXT("NOT ALL PEGS WERE SELECTED"))
			return;
		}

		if (rowOfPegs[i]->GetBigPegColor().GetValue() == SecretCode[i].GetValue())
		{
			// Give a Red Peg
			rowOfLittlePegs[i]->SetLittlePegColor(ELittlePegColors::LP_RED);
			slotCorrect[i] = true;
		}
	}

	// Now check for correct color pegs but in the wrong position
	if (rowOfPegs[0]->GetBigPegColor().GetValue() == SecretCode[1].GetValue() ||
		rowOfPegs[0]->GetBigPegColor().GetValue() == SecretCode[2].GetValue() ||
		rowOfPegs[0]->GetBigPegColor().GetValue() == SecretCode[3].GetValue())
	{
		rowOfLittlePegs[0]->SetLittlePegColor(ELittlePegColors::LP_WHITE);
	}
	if (rowOfPegs[1]->GetBigPegColor().GetValue() == SecretCode[0].GetValue() ||
		rowOfPegs[1]->GetBigPegColor().GetValue() == SecretCode[2].GetValue() ||
		rowOfPegs[1]->GetBigPegColor().GetValue() == SecretCode[3].GetValue())
	{
		rowOfLittlePegs[1]->SetLittlePegColor(ELittlePegColors::LP_WHITE);
	}
	if (rowOfPegs[2]->GetBigPegColor().GetValue() == SecretCode[0].GetValue() ||
		rowOfPegs[2]->GetBigPegColor().GetValue() == SecretCode[1].GetValue() ||
		rowOfPegs[2]->GetBigPegColor().GetValue() == SecretCode[3].GetValue())
	{
		rowOfLittlePegs[2]->SetLittlePegColor(ELittlePegColors::LP_WHITE);
	}
	if (rowOfPegs[3]->GetBigPegColor().GetValue() == SecretCode[0].GetValue() ||
		rowOfPegs[3]->GetBigPegColor().GetValue() == SecretCode[1].GetValue() ||
		rowOfPegs[3]->GetBigPegColor().GetValue() == SecretCode[2].GetValue())
	{
		rowOfLittlePegs[3]->SetLittlePegColor(ELittlePegColors::LP_WHITE);
	}

	if (slotCorrect[0] && slotCorrect[1] && slotCorrect[2] && slotCorrect[3])
	{
		// Player won the game!
		UE_LOG(LogTemp, Warning, TEXT("PLAYER WON!"))
	}
	else
	{
		// Give feedback and disable row
		DisableRow(rowOfPegs);
		if (currRow < 12)
		{
			EnableRow(nextRowOfPegs);
			currRow++; // May cause a bug
		}
	}

}

void DisableRow(TArray<ABigPeg*> row)
{
	for (int i = 0; i < row.Num(); ++i)
	{
		row[i]->SetPegEnabled(false);
	}
}

void EnableRow(TArray<ABigPeg*> row)
{
	for (int i = 0; i < row.Num(); ++i)
	{
		row[i]->SetPegEnabled(true);
	}
}