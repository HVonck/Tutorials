#include "DebugModels.h"
#include "GeometryGenerator.h"


DebugModels::DebugModels(DeferredRenderer* a_DeferredRenderer)
{
	GeometryGenerator gen;
	MeshData meshData;
	//Generate cube.
	gen.GenerateBox(1.0f, 1.0f, 1.0f, meshData);
	DirectXHelper::GenerateVertexBuffer(a_DeferredRenderer->GetDevice(), meshData, m_cube);
	//Generate sphere.
	gen.GenerateSphere(0.5f, DEBUG_DETAIL, DEBUG_DETAIL, meshData);
	DirectXHelper::GenerateVertexBuffer(a_DeferredRenderer->GetDevice(), meshData, m_sphere);
}


DebugModels::~DebugModels()
{
}

void DebugModels::Release()
{
	m_cube.Release();
	m_sphere.Release();
}
