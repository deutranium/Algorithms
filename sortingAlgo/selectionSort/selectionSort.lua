--- Sort an array using the selection sort algorithm.
--- @param t table
--- @return table
local function selectionSort(t)
    local n = #t
    for i = 1, n - 1 do
        local min = i
        for j = i + 1, n do
            if t[j] < t[min] then
                min = j
            end
        end
        t[i], t[min] = t[min], t[i]
    end
    return t
end

return selectionSort