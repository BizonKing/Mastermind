// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MastermindGameMode.h"
#include "MastermindCharacter.h"

AMastermindGameMode::AMastermindGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AMastermindCharacter::StaticClass();	
}
