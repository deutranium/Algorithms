local function shellSort(t)
    local n = #t
    local gap = math.floor(n / 2)
    while gap > 0 do
        for i = gap + 1, n do
            local item = t[i]
            local j = i - gap
            while j > 0 and t[j] > item do
                t[j + gap] = t[j]
                j = j - gap
            end
            t[j + gap] = item
        end
        gap = math.floor(gap / 2)
    end
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
shellSort(t)
print(table.concat(t, ", "))