
import React, { useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import { Badge } from '@/components/ui/badge';
import { Separator } from '@/components/ui/separator';
import { Calculator, Code, Target, TrendingUp } from 'lucide-react';

const Index = () => {
  const [arr, setArr] = useState<number[]>([1, 3, 4, 10, 12]);
  const [k, setK] = useState<number>(2);
  const [x, setX] = useState<number>(4);
  const [result, setResult] = useState<number[]>([]);
  const [arrayInput, setArrayInput] = useState<string>("1,3,4,10,12");
  const [steps, setSteps] = useState<string[]>([]);

  const findKClosestElements = () => {
    // Filter out x if it exists
    const filteredArr = arr.filter(num => num !== x);
    const stepsList: string[] = [];
    
    stepsList.push(`Original array: [${arr.join(', ')}]`);
    stepsList.push(`Target x = ${x}, k = ${k}`);
    stepsList.push(`Filtered array (excluding ${x}): [${filteredArr.join(', ')}]`);
    
    // Calculate distances and create pairs
    const distances = filteredArr.map(num => ({
      value: num,
      distance: Math.abs(num - x)
    }));
    
    stepsList.push(`Calculating distances from ${x}:`);
    distances.forEach(item => {
      stepsList.push(`  ${item.value}: |${item.value} - ${x}| = ${item.distance}`);
    });
    
    // Sort by distance, then by value (larger first for ties)
    distances.sort((a, b) => {
      if (a.distance !== b.distance) {
        return a.distance - b.distance;
      }
      return b.value - a.value; // Prefer larger element for ties
    });
    
    stepsList.push(`Sorted by distance (larger element preferred for ties):`);
    distances.forEach((item, index) => {
      stepsList.push(`  ${index + 1}. ${item.value} (distance: ${item.distance})`);
    });
    
    // Take first k elements
    const kClosest = distances.slice(0, k).map(item => item.value);
    
    stepsList.push(`Taking first ${k} elements: [${kClosest.join(', ')}]`);
    
    setSteps(stepsList);
    setResult(kClosest);
  };

  const handleArrayInputChange = (value: string) => {
    setArrayInput(value);
    try {
      const newArr = value.split(',').map(num => parseInt(num.trim())).filter(num => !isNaN(num));
      setArr(newArr);
    } catch (error) {
      console.log("Invalid array input");
    }
  };

  const cppSolution = `vector<int> kClosestElements(vector<int>& arr, int k, int x) {
    // Filter out x if it exists
    vector<int> filtered;
    for (int num : arr) {
        if (num != x) {
            filtered.push_back(num);
        }
    }
    
    // Create pairs of (value, distance)
    vector<pair<int, int>> distances;
    for (int num : filtered) {
        distances.push_back({num, abs(num - x)});
    }
    
    // Sort by distance, then by value (larger first for ties)
    sort(distances.begin(), distances.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }
        return a.first > b.first; // Prefer larger element for ties
    });
    
    // Extract first k elements
    vector<int> result;
    for (int i = 0; i < k && i < distances.size(); i++) {
        result.push_back(distances[i].first);
    }
    
    return result;
}`;

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-50 via-indigo-50 to-purple-50 p-4">
      <div className="max-w-6xl mx-auto space-y-6">
        {/* Header */}
        <div className="text-center space-y-2">
          <div className="flex items-center justify-center gap-2 mb-4">
            <Target className="h-8 w-8 text-blue-600" />
            <h1 className="text-4xl font-bold bg-gradient-to-r from-blue-600 to-purple-600 bg-clip-text text-transparent">
              K Closest Elements Solver
            </h1>
          </div>
          <p className="text-lg text-gray-600 max-w-2xl mx-auto">
            Find k elements closest to a target value from a sorted array with interactive visualization
          </p>
        </div>

        <div className="grid grid-cols-1 lg:grid-cols-2 gap-6">
          {/* Input Section */}
          <Card className="shadow-lg border-0 bg-white/70 backdrop-blur-sm">
            <CardHeader className="bg-gradient-to-r from-blue-500 to-purple-500 text-white rounded-t-lg">
              <CardTitle className="flex items-center gap-2">
                <Calculator className="h-5 w-5" />
                Problem Input
              </CardTitle>
            </CardHeader>
            <CardContent className="space-y-4 p-6">
              <div>
                <Label htmlFor="array" className="text-sm font-medium">
                  Sorted Array (comma-separated)
                </Label>
                <Input
                  id="array"
                  value={arrayInput}
                  onChange={(e) => handleArrayInputChange(e.target.value)}
                  placeholder="1,3,4,10,12"
                  className="mt-1"
                />
              </div>
              
              <div className="grid grid-cols-2 gap-4">
                <div>
                  <Label htmlFor="k" className="text-sm font-medium">
                    K (number of elements)
                  </Label>
                  <Input
                    id="k"
                    type="number"
                    value={k}
                    onChange={(e) => setK(parseInt(e.target.value) || 0)}
                    min="1"
                    className="mt-1"
                  />
                </div>
                
                <div>
                  <Label htmlFor="x" className="text-sm font-medium">
                    Target X
                  </Label>
                  <Input
                    id="x"
                    type="number"
                    value={x}
                    onChange={(e) => setX(parseInt(e.target.value) || 0)}
                    className="mt-1"
                  />
                </div>
              </div>
              
              <Button 
                onClick={findKClosestElements} 
                className="w-full bg-gradient-to-r from-blue-500 to-purple-500 hover:from-blue-600 hover:to-purple-600 text-white font-medium py-2 px-4 rounded-lg transition-all duration-200 transform hover:scale-105"
              >
                <TrendingUp className="h-4 w-4 mr-2" />
                Find K Closest Elements
              </Button>
            </CardContent>
          </Card>

          {/* Result Section */}
          <Card className="shadow-lg border-0 bg-white/70 backdrop-blur-sm">
            <CardHeader className="bg-gradient-to-r from-green-500 to-teal-500 text-white rounded-t-lg">
              <CardTitle className="flex items-center gap-2">
                <Target className="h-5 w-5" />
                Solution Result
              </CardTitle>
            </CardHeader>
            <CardContent className="p-6">
              {result.length > 0 ? (
                <div className="space-y-4">
                  <div>
                    <h3 className="font-semibold text-lg mb-2">Result:</h3>
                    <div className="flex flex-wrap gap-2">
                      {result.map((num, index) => (
                        <Badge 
                          key={index} 
                          variant="secondary" 
                          className="text-lg px-3 py-1 bg-gradient-to-r from-green-100 to-teal-100 text-green-800 border border-green-200"
                        >
                          {num}
                        </Badge>
                      ))}
                    </div>
                  </div>
                  
                  <div>
                    <h3 className="font-semibold text-lg mb-2">Array Visualization:</h3>
                    <div className="flex flex-wrap gap-2">
                      {arr.map((num, index) => (
                        <Badge 
                          key={index}
                          variant={num === x ? "destructive" : result.includes(num) ? "default" : "outline"}
                          className={`text-sm px-2 py-1 ${
                            num === x 
                              ? "bg-red-100 text-red-800 border-red-200" 
                              : result.includes(num) 
                                ? "bg-blue-100 text-blue-800 border-blue-200" 
                                : "bg-gray-100 text-gray-600 border-gray-200"
                          }`}
                        >
                          {num}
                          {num === x && " (excluded)"}
                        </Badge>
                      ))}
                    </div>
                    <div className="text-xs text-gray-500 mt-2">
                      <span className="inline-block w-3 h-3 bg-red-100 border border-red-200 rounded mr-1"></span>Excluded (target)
                      <span className="inline-block w-3 h-3 bg-blue-100 border border-blue-200 rounded mr-1 ml-3"></span>Selected
                      <span className="inline-block w-3 h-3 bg-gray-100 border border-gray-200 rounded mr-1 ml-3"></span>Not selected
                    </div>
                  </div>
                </div>
              ) : (
                <p className="text-gray-500 text-center py-8">
                  Click "Find K Closest Elements" to see the result
                </p>
              )}
            </CardContent>
          </Card>
        </div>

        {/* Algorithm Steps */}
        {steps.length > 0 && (
          <Card className="shadow-lg border-0 bg-white/70 backdrop-blur-sm">
            <CardHeader className="bg-gradient-to-r from-purple-500 to-pink-500 text-white rounded-t-lg">
              <CardTitle>Algorithm Steps</CardTitle>
            </CardHeader>
            <CardContent className="p-6">
              <div className="space-y-2">
                {steps.map((step, index) => (
                  <div key={index} className={`${step.startsWith('  ') ? 'ml-4 text-gray-600' : 'font-medium'}`}>
                    {step.startsWith('  ') ? step : `${index + 1}. ${step}`}
                  </div>
                ))}
              </div>
            </CardContent>
          </Card>
        )}

        {/* C++ Solution */}
        <Card className="shadow-lg border-0 bg-white/70 backdrop-blur-sm">
          <CardHeader className="bg-gradient-to-r from-gray-700 to-gray-900 text-white rounded-t-lg">
            <CardTitle className="flex items-center gap-2">
              <Code className="h-5 w-5" />
              C++ Solution
            </CardTitle>
          </CardHeader>
          <CardContent className="p-6">
            <pre className="bg-gray-100 p-4 rounded-lg overflow-x-auto text-sm">
              <code className="language-cpp">{cppSolution}</code>
            </pre>
          </CardContent>
        </Card>

        {/* Problem Description */}
        <Card className="shadow-lg border-0 bg-white/70 backdrop-blur-sm">
          <CardHeader className="bg-gradient-to-r from-indigo-500 to-blue-500 text-white rounded-t-lg">
            <CardTitle>Problem Description</CardTitle>
          </CardHeader>
          <CardContent className="p-6 space-y-4">
            <div>
              <h3 className="font-semibold mb-2">Problem:</h3>
              <p className="text-gray-700">
                Given a sorted array of unique integers, an integer k, and a target value x, 
                return exactly k elements from the array closest to x, excluding x if it exists.
              </p>
            </div>
            
            <Separator />
            
            <div>
              <h3 className="font-semibold mb-2">Closeness Rules:</h3>
              <ul className="list-disc list-inside space-y-1 text-gray-700">
                <li>Element a is closer to x than b if |a - x| &lt; |b - x|</li>
                <li>If |a - x| == |b - x|, prefer the larger element (a &gt; b)</li>
              </ul>
            </div>
            
            <Separator />
            
            <div>
              <h3 className="font-semibold mb-2">Algorithm Complexity:</h3>
              <ul className="list-disc list-inside space-y-1 text-gray-700">
                <li><strong>Time Complexity:</strong> O(n log n) for sorting</li>
                <li><strong>Space Complexity:</strong> O(n) for storing distances</li>
              </ul>
            </div>
          </CardContent>
        </Card>
      </div>
    </div>
  );
};

export default Index;
