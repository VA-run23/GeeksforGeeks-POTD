# Comparison of Search Algorithms

## Master Comparison Table

| Algorithm | Time Complexity | Space Complexity | Nodes Expanded | Completeness | Optimality | Key Advantages | Key Disadvantages |
|-----------|----------------|------------------|----------------|--------------|------------|----------------|-------------------|
| **Breadth-First Search (BFS)** | O(b^d) | O(b^d) | All nodes up to depth *d* | ✅ Complete | ✅ Optimal (unit costs) | • Guaranteed to find shallowest solution<br>• Systematic level-by-level exploration | • Exponential memory usage<br>• Extremely slow for deep solutions |
| **Depth-First Search (DFS)** | O(b^m) | O(b·m) | Potentially all nodes to max depth *m* | ❌ Incomplete (infinite spaces) | ❌ Not optimal | • Linear space complexity<br>• Very memory efficient<br>• Simple implementation | • Can get stuck in infinite branches<br>• May miss shallow solutions<br>• Not optimal |
| **Depth-Limited Search (DLS)** | O(b^ℓ) | O(b·ℓ) | All nodes up to depth limit *ℓ* | ❌ Incomplete if ℓ < d | ❌ Not optimal | • Prevents infinite loops<br>• Memory efficient like DFS<br>• Good when depth bound known | • Fails if limit too shallow<br>• Not optimal<br>• Choosing correct limit is difficult |
| **Iterative Deepening DFS (IDDFS)** | O(b^d) | O(b·d) | All nodes to depth *d*, repeated per iteration | ✅ Complete | ✅ Optimal (unit costs) | • Combines BFS completeness with DFS space efficiency<br>• Best of both worlds<br>• No depth limit needed | • Redundant node re-expansion<br>• Still exponential time complexity |
| **Uniform Cost Search (UCS)** | O(b^(1+⌊C*/ε⌋)) | O(b^(1+⌊C*/ε⌋)) | All nodes with cost ≤ C* | ✅ Complete | ✅ Optimal (non-negative costs) | • Handles variable step costs<br>• Optimal for weighted graphs<br>• Expands lowest-cost paths first | • Large memory requirements<br>• Priority queue overhead<br>• Slow for large state spaces |

---

## Key Terms

| Symbol | Meaning |
|--------|---------|
| **b** | Branching factor (average children per node) |
| **d** | Depth of shallowest goal node |
| **m** | Maximum depth of search tree |
| **ℓ** | Depth limit (for DLS) |
| **C*** | Cost of optimal solution path |
| **ε** | Minimum positive step cost |

---

## Quick Selection Guide

**Use BFS when:**
- Memory is not a constraint
- Solution is likely shallow
- All step costs are identical
- You need the shortest path

**Use DFS when:**
- Memory is severely limited
- Solutions are deep
- You don't need the optimal solution
- Space has finite depth

**Use DLS when:**
- You know approximate solution depth
- Need to avoid infinite paths
- Memory is limited

**Use IDDFS when:**
- You want BFS optimality with DFS memory efficiency
- Solution depth is unknown
- Step costs are uniform
- Memory is limited

**Use UCS when:**
- Step costs vary
- You need optimal solution for weighted graphs
- Memory is available
- All costs are non-negative