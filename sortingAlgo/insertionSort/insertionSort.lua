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
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
insertionSort(t)
print(table.concat(t, ", "))