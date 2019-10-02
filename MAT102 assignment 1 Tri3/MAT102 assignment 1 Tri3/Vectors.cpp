#include "Vectors.h"
#include <cmath>	


bool Equals(const TVector3& _krA, const TVector3& _krB)
{
	if ((_krA.m_fX == _krB.m_fX) && (_krA.m_fY == _krB.m_fY) && (_krA.m_fZ == _krB.m_fZ)) {
		return true;
	}
	else {
		return false;
	}


};


TVector3& Add(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;
	return _rResultant;
};


TVector3& Subtract(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
};

TVector3& ScaleVector(const TVector3& _krA, const float _kfScalar, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX * _kfScalar;
	_rResultant.m_fY = _krA.m_fY * _kfScalar;
	_rResultant.m_fZ = _krA.m_fZ * _kfScalar;
	return _rResultant;
};

float Magnitude(const TVector3& _krA)
{
	float magnitude = 0;
	magnitude = sqrt((_krA.m_fX * _krA.m_fX) + (_krA.m_fY * _krA.m_fY) + (_krA.m_fZ * _krA.m_fZ));
	return magnitude;
};

float DotProduct(const TVector3& _krA, const TVector3& _krB)
{
	float dotProduct = 0;
	dotProduct = (_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ);
	return dotProduct;

};

TVector3& CrossProduct(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = (_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY);
	_rResultant.m_fY = (_krA.m_fX * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fX);
	_rResultant.m_fZ = (_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX);
	return _rResultant;
};

TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant)
{
	_rResultant.m_fX = (_krA.m_fX / sqrt(_krA.m_fX * _krA.m_fX));
	_rResultant.m_fY = (_krA.m_fY / sqrt(_krA.m_fY * _krA.m_fY));
	_rResultant.m_fZ = (_krA.m_fZ / sqrt(_krA.m_fZ * _krA.m_fZ));
	return _rResultant;

};

TVector3& Projection(const TVector3& _krA, const TVector3& _krB, TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
};

float ComputeAngleBetween(const TVector2& _krA, const TVector2& _krB)
{
	//TODO: FIND WHY THIS RETURNS NAN
	float angle = 0;
	angle = acos(((_krA.m_fX * _krB.m_fX) * (_krA.m_fY * _krB.m_fY)) / (sqrt((_krA.m_fX * _krA.m_fX) + (_krA.m_fY * _krA.m_fY)) * sqrt((_krB.m_fX * _krB.m_fX) + (_krB.m_fY + _krB.m_fY))));
	return angle;
};

float ComputeAngleBetween(const TVector3& _krA, const TVector3& _krB)
{
	//TOOD: write test for angle between 2 3d vectors
	float angle = 0;
	angle = acos(((_krA.m_fX * _krB.m_fX) * (_krA.m_fY * _krB.m_fY) * (_krA.m_fZ * _krB.m_fZ)) / (sqrt((_krA.m_fX * _krA.m_fX) + (_krA.m_fY * _krA.m_fY)) * sqrt((_krB.m_fX * _krB.m_fX) + (_krB.m_fY + _krB.m_fY)) + sqrt((_krA.m_fZ * _krA.m_fZ) + (_krB.m_fZ * _krB.m_fZ))));
	return angle;
};

float ComputeDistancePointToLine(const T3DLine& _krLine, const TVector3& _krPoint)
{
	//TVector3 m_v3q; //point on the line
	//TVector3 m_v3v; //direction vector along the line
	float dist = 0, DirectionMagnitude = 0, MagnitudeCrossProduct;
	TVector3 CrossProduct1;
	CrossProduct1 = CrossProduct(_krPoint, _krLine.m_v3q, CrossProduct1);
	MagnitudeCrossProduct = sqrt((CrossProduct1.m_fX * CrossProduct1.m_fX) + (CrossProduct1.m_fY * CrossProduct1.m_fY) + (CrossProduct1.m_fZ * CrossProduct1.m_fZ));
	DirectionMagnitude = sqrt((_krLine.m_v3v.m_fX * _krLine.m_v3v.m_fX) + (_krLine.m_v3v.m_fY * _krLine.m_v3v.m_fY) + (_krLine.m_v3v.m_fZ * _krLine.m_v3v.m_fZ));

	dist = MagnitudeCrossProduct / DirectionMagnitude;


	return dist;
};

float ComputeDistancePointToPlane(const TPlane& _krPlane, const TVector3& _krPoint)
{
	//TODO: return distance Point to Plane
	//create return varaiable
	float dist = 0;
	return dist;
};

float ComputeDistancePointToSphere(const TSphere& _krSphere, const TVector3& _krPoint)
{
	//TODO: return distance point to point on centre of spheres, then subtract radii
	float dist = 0;
	dist = sqrt((_krSphere.m_v3center.m_fX * _krSphere.m_v3center.m_fX) + (_krSphere.m_v3center.m_fY * _krSphere.m_v3center.m_fY) + (_krSphere.m_v3center.m_fZ * _krSphere.m_v3center.m_fZ) + (_krPoint.m_fX * _krPoint.m_fX) + (_krPoint.m_fY * _krPoint.m_fY) + (_krPoint.m_fZ * _krPoint.m_fZ));
	dist -= _krSphere.m_fRadius;
	return dist;
};

float ComputeDistanceCircleToCircle(const TCircle& _krCircle1, const TCircle& _krCircle2)
{
	//TODO: return distance between 2 circles
	//create return variable
	float dist = 0;
	dist = sqrt((_krCircle1.m_v2center.m_fX * _krCircle1.m_v2center.m_fX) + (_krCircle1.m_v2center.m_fY * _krCircle1.m_v2center.m_fY) + (_krCircle2.m_v2center.m_fX * _krCircle2.m_v2center.m_fX) + (_krCircle2.m_v2center.m_fY* _krCircle2.m_v2center.m_fY));
	dist -= (_krCircle1.m_fRadius + _krCircle2.m_fRadius);
	return dist;
};

float ComputeDistanceCircleToTriangle(const TCircle& _krCircle, const TTriangle2& _krTriangle)
{
	//TODO: return distance between two triangles
	//crete return variable
	float dist = 0, Vect1 = 0, Vect2 = 0, Vect3 = 0;
	Vect1 = sqrt((_krCircle.m_v2center.m_fX * _krCircle.m_v2center.m_fX) + (_krCircle.m_v2center.m_fY * _krCircle.m_v2center.m_fY) + (_krTriangle.m_v2p1.m_fX * _krTriangle.m_v2p1.m_fX) + (_krTriangle.m_v2p1.m_fY * _krTriangle.m_v2p1.m_fY));
	Vect2 = sqrt((_krCircle.m_v2center.m_fX * _krCircle.m_v2center.m_fX) + (_krCircle.m_v2center.m_fY * _krCircle.m_v2center.m_fY) + (_krTriangle.m_v2p2.m_fX * _krTriangle.m_v2p2.m_fX) + (_krTriangle.m_v2p2.m_fY * _krTriangle.m_v2p2.m_fY));
	Vect3 = sqrt((_krCircle.m_v2center.m_fX * _krCircle.m_v2center.m_fX) + (_krCircle.m_v2center.m_fY * _krCircle.m_v2center.m_fY) + (_krTriangle.m_v2p3.m_fX * _krTriangle.m_v2p3.m_fX) + (_krTriangle.m_v2p3.m_fY * _krTriangle.m_v2p3.m_fY));
	if (Vect1 < Vect2 && Vect1 < Vect3) {
		dist = Vect1;
	}
	if (Vect2 < Vect1 && Vect2 < Vect3) {
		dist = Vect2;
	}
	if (Vect3 < Vect1 && Vect3 < Vect2) {
		dist = Vect3;
	}
	dist -= _krCircle.m_fRadius;
	return dist;
};

EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine, const TSphere& _krSphere, TVector3& _rv3IntersectionPoint1, TVector3& _rv3IntersectionPoint2)
{
	//TODO: return Line Sphere Intersection
	//TODO: return _rv3IntersectionPoint1, _rv3IntersectionPoint2;
	float distLineToCentre = 0;
	distLineToCentre = ComputeDistancePointToLine(_krLine, _krSphere.m_v3center);
	if (distLineToCentre > _krSphere.m_fRadius) {
		return EIntersections::INTERSECTION_NONE;
	}
	else if (distLineToCentre == _krSphere.m_fRadius) {
		return EIntersections::INTERSECTION_ONE;
	}
	else if (distLineToCentre < _krSphere.m_fRadius) {
		return EIntersections::INTERSECTION_TWO;
	}
	// Unsure how to return points of intersection at this time
};

bool IsLinePlaneIntersection(const T3DLine& _krLine, const TPlane& _krPlane, TVector3& _rv3IntersectionPoint)
{
	//TODO: return true false of line touching plane
	//return _rv3IntersectionPoint; boolean
	bool intersect = false;
	float empty = 0;
	if (DotProduct(_krLine.m_v3v, _krPlane.m_v3normal) == 0) {
		TVector3 Subtracted = Subtract(_krPlane.m_v3point, _krLine.m_v3q, Subtracted);
		if (DotProduct(Subtracted, _krPlane.m_v3normal) == 0) {
			intersect = true;
		}
		else if (DotProduct(Subtracted, _krPlane.m_v3normal) != 0) {
			intersect = false;
		}
	}
	return intersect;
};

bool IsIntersection(const T3DLine& _krLine1, const T3DLine& _krLine2)
{
	//TODO: return intersection true false
	//create return variable
	bool intersect = false;
	return intersect;
};

TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1, const T3DLine& _krLine2, TVector3& _rIntersectionPoint)
{
	//TODO: return intersection between lines in 3D space
	return _rIntersectionPoint;
};

bool IsInFieldOfView(const TVector2& _krCameraPosition, const TVector2& _krCameraDirection, const float _kfFieldOfViewInRadians, const TVector2& _krObjectPosition)
{
	//TODO: is something in the feild of view
	//create return variable
	bool visible = false;
	return visible;
};

TVector3& FindTriangleNormal(const TTriangle3& _krTriangle, TVector3& _rNormal)
{
	//TODO: find the up of a triangle
	return _rNormal;
};

bool IsSurfaceLit(const TVector3& _krPointOnSurface, const TVector3& _krLightSourcePosition, const TTriangle3& _krSurface)
{
	//TOOD: Return T/F based on 
	//create return variable
	bool lit = false;
	return lit;
};

TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle, const float _kfRotAngleInRadians, const TVector2& _krRotAroundPoint, TTriangle2& _rRotatedTriangle)
{
	//TODO return information about rotating triangle around a point 
	return _rRotatedTriangle;
};
