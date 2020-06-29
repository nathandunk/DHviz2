using System.IO;
// using UnityEditor;
using System.Collections.Generic;
using UnityEditor.Scripting.Python;
using UnityEngine;
using Python.Runtime;

/// <summary>
/// Example class to showcase the base EvalExec client.
/// </summary>
public class DynamicsClientHandler
{
    /// <summary>
    /// Hack to get the current file's directory
    /// </summary>
    /// <param name="fileName">Leave it blank to the current file's directory</param>
    /// <returns></returns>
    private static string __DIR__([System.Runtime.CompilerServices.CallerFilePath] string fileName = "")
    {
        return Path.GetDirectoryName(fileName);
    }

    /// <summary>
    /// The client's unique name, which will be referred to in calls from Unity, as well as used for logging.
    /// </summary>
    const string ClientName = "dynamics.client";

    /// <summary>
    /// Example method that sends an exec command to a running EvalExec client.
    /// Similar to calling the `exec` builtin Python function.
    /// </summary>
    // [MenuItem("Dynamics/RunDynamics")]
    public static void RunDynamics(List<double> a_, List<double> alpha_, List<double> d_, List<double> theta_)
    {
        // A client must exist for the service to successfully be run. See the SpawnClient() method and associated comments.
        List<List<double>> test3 = new List<List<double>>(){a_,alpha_,d_,theta_};
        PythonRunner.CallServiceOnClient(ClientName, "test", test3);
        // Debug.Log("ran 'exec(\"x = 6\")'");
    }

    /// <summary>
    /// Example method that sends an eval command to a running EvalExec client.
    /// Similar to calling the `eval` builtin Python function.
    /// </summary>
    // [MenuItem("Python/Examples/Eval-exec Example/Send eval")]
    // public static void SendEval()
    // {
    //     Debug.Log("running 'eval(\"x\")'");
    //     // A (Py.GIL()) block must be used to ensure stability by holding the Python global interpreter lock.
    //     using (Py.GIL()) {
    //         // If it is not needed, the return value can safely be discarded.
    //         dynamic x = PythonRunner.CallServiceOnClient(ClientName, "eval", "x");
    //         Debug.Log($"ran 'eval(\"x\")' and got {x}");
    //     }
    // }

    /// <summary>
    /// Starts the EvalExec client.
    /// </summary>
    // [MenuItem("Dynamics/Spawn client")]
    public static void SpawnClient()
    {
        // The client here spawned could also be launched from the command line.
        PythonRunner.SpawnClient(file: $"{__DIR__()}/DynamicsClient.py",
                wantLogging: true);
    }
}
