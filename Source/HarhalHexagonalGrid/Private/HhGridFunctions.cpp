// Fill out your copyright notice in the Description page of Project Settings.


#include "HhGridFunctions.h"

#include "MathUtil.h"

FHhAxialCoord UHhGridFunctions::MakeHexAxialCoordFromSpiral(const int32 n)
{ 
	const int32 Radius = FMathf::Floor((FMathf::Sqrt(12.f * n - 3.f) + 3.f) / 6.f);
	if (Radius <= 0)
	{
		return FHhAxialCoord(0, 0);
	}
	
	const int32 RingStart = 1 + 3 * Radius * (Radius - 1);
	const int32 RingLocalN = n - RingStart;
	const int32 LineLocalN = RingLocalN % Radius;
	
	switch (RingLocalN / Radius)
	{
		case 0:
			return FHhAxialCoord(Radius - LineLocalN, LineLocalN);
		case 1:
			return FHhAxialCoord(- LineLocalN, Radius);
		case 2:
			return FHhAxialCoord(- Radius, Radius - LineLocalN);
		case 3:
			return FHhAxialCoord(LineLocalN - Radius, - LineLocalN);
		case 4:
			return FHhAxialCoord(LineLocalN, -Radius);
		case 5:
			return FHhAxialCoord(Radius, LineLocalN - Radius);
		default: 
			return FHhAxialCoord(0, 0);
	}
}

int32 UHhGridFunctions::GetHexSpiralLength(const int32 r)
{
	return 1 + 3 * r * (r + 1);
}

FVector2D UHhGridFunctions::HexAxialCoordToPoint(const FHhAxialCoord& Coord, const float CellBigRadius)
{
	const float x = FMath::Sqrt(3.f) * Coord.GetQ()  +  sqrt(3)/2 * Coord.GetR();
	const float y = 3.f/2.f * Coord.GetR();

	return FVector2D(x, y) * CellBigRadius;
}

FHhAxialCoord UHhGridFunctions::PointToHexAxialCoord(const FVector2D& Point, const float CellBigRadius)
{
	if (CellBigRadius <= 0.f)
	{
		return FHhAxialCoord(0, 0);
	}

	// Inverse of HexAxialCoordToPoint; the float constructor rounds to the nearest cell in cube space.
	const float q = (FMath::Sqrt(3.f) / 3.f * Point.X - 1.f / 3.f * Point.Y) / CellBigRadius;
	const float r = (2.f / 3.f * Point.Y) / CellBigRadius;
	return FHhAxialCoord(q, r);
}

int32 UHhGridFunctions::GetHexDistance(const FHhAxialCoord& A, const FHhAxialCoord& B)
{
	const int32 DQ = A.CellCoord.X - B.CellCoord.X;
	const int32 DR = A.CellCoord.Y - B.CellCoord.Y;
	return (FMath::Abs(DQ) + FMath::Abs(DR) + FMath::Abs(DQ + DR)) / 2;
}
