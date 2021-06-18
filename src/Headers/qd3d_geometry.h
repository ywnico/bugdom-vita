//
// qd3d_geometry.h
//

#include "qd3d_support.h"


enum
{
	PARTICLE_MODE_BOUNCE = (1),
	PARTICLE_MODE_UPTHRUST = (1<<1),
	PARTICLE_MODE_HEAVYGRAVITY = (1<<2),
	PARTICLE_MODE_NULLSHADER = (1<<3)
};


#define	MAX_PARTICLES2		80

typedef struct
{
	Boolean					isUsed;
	TQ3Vector3D				rot,rotDelta;
	TQ3Point3D				coord,coordDelta;
	float					decaySpeed,scale;
	Byte					mode;
	TQ3Matrix4x4			matrix;
	TQ3TriMeshData			*mesh;
}ParticleType;

void QD3D_CalcObjectBoundingBox(int numMeshes, TQ3TriMeshData** meshList, TQ3BoundingBox* boundingBox);
void QD3D_CalcObjectBoundingSphere(int numMeshes, TQ3TriMeshData** meshList, TQ3BoundingSphere* boundingSphere);
void QD3D_ExplodeGeometry(ObjNode *theNode, float boomForce, Byte particleMode, int particleDensity, float particleDecaySpeed);
extern	void QD3D_ReplaceGeometryTexture(TQ3Object obj, TQ3SurfaceShaderObject theShader);
void QD3D_ScrollUVs(TQ3TriMeshData* meshList, float du, float dv);
extern	void QD3D_InitParticles(void);
extern	void QD3D_MoveParticles(void);
void QD3D_DrawParticles(const QD3DSetupOutputType *setupInfo);

void ForEachTriMesh(TQ3Object root, void (*callback)(TQ3TriMeshData triMeshData, void* userData), void* userData, uint64_t triMeshMask);

void QD3D_ClearDiffuseColor_TriMesh(TQ3TriMeshData triMeshData, void* userData_unused);

ObjNode* MakeNewDisplayGroupObject_TexturedQuad(TQ3SurfaceShaderObject surfaceShader, float aspectRatio);

TQ3TriMeshData* MakeQuadMesh(int numQuads);
