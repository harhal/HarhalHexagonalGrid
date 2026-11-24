# HarhalHexagonalGrid

Unreal Engine 5 runtime plugin with hexagonal grid utilities, independent of any game code.

- `FHhAxialCoord` — axial hex coordinates (cube rounding from float coordinates).
- `UHhGridFunctions` — spiral indexing (`MakeHexAxialCoordFromSpiral`, `GetHexSpiralLength`),
  axial → 2D point conversion.
- `UHhGridPlane` — scene component mapping world points to hex cells and back.
- `SHhGridPanel` / `UHhGridPanelWidget` — Slate panel and UMG wrapper that lay out children on a hex grid.

## Usage

Add to a project as a git submodule under `Plugins/`:

```
git submodule add <url> Plugins/HarhalHexagonalGrid
```

and add `"HarhalHexagonalGrid"` to the dependent module's `Build.cs`.

## Tests

Automation tests live in `Source/HarhalHexagonalGrid/Private/Tests` (`HarhalHexagonalGrid.*`).
