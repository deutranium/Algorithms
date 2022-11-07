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
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
countingSort(t)
print(table.concat(t, ", "))