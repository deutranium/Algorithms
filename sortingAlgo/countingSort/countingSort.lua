--- Sort an array using counting sort algorithm.
--- @param t table
--- @return table
local function countingSort(t)
    local n = #t
    local counts = {}
    for i = 1, n do
        counts[t[i]] = (counts[t[i]] or 0) + 1
    end
    local k = 1
    for i = 1, n do
        if counts[i] then
            for j = 1, counts[i] do
                t[k] = i
                k = k + 1
            end
        end
    end
    return t
end

return countingSort