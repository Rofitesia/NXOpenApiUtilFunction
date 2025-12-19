using System;
using System.Collections.Generic;
using NXOpen;
using NXOpen.UF;

List<Point3d> getPointFromFace(Face face, int uvSample = 3){
    var points = new List<Point3d>();
    UFSession uf = UFSession.GetUFSession();
    Tag faceTag = face.Tag;
    IntPtr evaluator;
    uf.Evalsf.Initialize(faceTag, out evaluator);
    try{
        double[] uvBox = new double[4]; 
        uf.Evalsf.AskFaceUvMinmax(evaluator, uvBox);
        double uMin = uvBox[0];
        double uMax = uvBox[1];
        double vMin = uvBox[2];
        double vMax = uvBox[3];
        double step = 1.0 / uvSample;
        for(int i=1;i<=uvSample;++i)
        {
            double[] uvPair = new double[2];
            uvPair[0] = uMin + i * step * (uMax-uMin);
            for(int j=1; j<=uvSample; j++)
            {
                uvPair[1] = vMin + i * step * (vMax-vMin);
                ModlSrfValue  srfValue;
                uf.Evalsf.Evaluate(
                        evaluator,
                        UFConstants.UF_MODL_EVAL,
                        uvPair,
                        out srfValue);
                Point3d pt = new Point3d(
                        srfValue.srf_pos[0],
                        srfValue.srf_pos[1],
                        srfValue.srf_pos[2]);
                int status;
                uf.Modl.IsPointOnFace(faceTag, pt, out status);

                if (status == UFConstants.UF_MODL_POINT_ON_FACE)
                {
                    points.Add(pt);
                }
            }
        }
    }
    finally
    {
        uf.Evalsf.Free(evaluator);
    }
    return points;
}


Session theSession = Session::GetSession();
Part workPart = theSession.Parts.Work;


// wall thickness analysis
Tooling::WallThicknessCheckerBuilder thicknessBuilder = workPart.ToolingManager.WallThicknessChecker.CreateBuilder();
thicknessBuilder.InitThicknessData();
thicknessBuilder.CalculationCalculateMethod = Tooling.WallThicknessCheckerBuilder.CalculateMethod::RollingBall;
thicknessBuilder.CalculationMaximumThicknessTolerance = 0.0732509284915600;
thicknessBuilder.CalculationMaximumSpacing = 4.9444376731805;
thicknessBuilder.Calculate();

// get body
// get body using thicknessBuilder
Body targetBody = thicknessBuilder.CalculationBody.Value;
// get body using working Part
Body[] targetBodies = workPart.Bodies.ToArray();
// extract all target faces
List<Face> targetFaces;
foreach(var body in targetBodies){
    targetFaces.AddRange(body.GetFaces());    
}

var allPoints = new List<Point3d>();
foreach(var face in targetFaces){
    allPoints.AddRange(getPointFromFace(face));
}


