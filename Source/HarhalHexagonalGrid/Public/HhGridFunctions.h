// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HhAxialCoord.h"
#include "HhGridFunctions.generated.h"

/**
 * 
 */
UCLASS()
class HARHALHEXAGONALGRID_API UHhGridFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static FHhAxialCoord MakeHexAxialCoordFromSpiral(const int32 n);
	
	UFUNCTION(BlueprintPure)
	static int32 GetHexSpiralLength(const int32 r);
	
	UFUNCTION(BlueprintPure)
	static FVector2D HexAxialCoordToPoint(const FHhAxialCoord& Coord, const float CellBigRadius);

	/** Inverse of HexAxialCoordToPoint: the cell containing Point (pointy-top hexes, origin at the centre of (0,0)). */
	UFUNCTION(BlueprintPure)
	static FHhAxialCoord PointToHexAxialCoord(const FVector2D& Point, const float CellBigRadius);

	/** Number of steps between two cells. */
	UFUNCTION(BlueprintPure)
	static int32 GetHexDistance(const FHhAxialCoord& A, const FHhAxialCoord& B);
};
