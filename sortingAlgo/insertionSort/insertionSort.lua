--- Sort an array using the insertion sort algorithm.
--- @param t table
--- @return table
local function insertionSort(t)
    local n = #t
    for i = 2, n do
        local item = t[i]
        local j = i - 1
        while j > 0 and t[j] > item do
            t[j + 1] = t[j]
            j = j - 1
        end
        t[j + 1] = item
    end
    return t
end

return insertionSort