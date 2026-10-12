#pragma once

#include <Rendering\Data\VertexData.h>

#include <vector>

class MeshData
{
public :
	MeshData();
	virtual ~MeshData() = default;

	inline const std::vector<int>& GetIndices() const { return indices; }

protected :
	std::vector<VertexData> vertices;
	std::vector<int> indices;
};